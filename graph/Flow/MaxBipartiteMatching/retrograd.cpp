Sourec   :  https://github.com/bicsi/code_snippets/blob/master/bipartite_match.cpp
         :  https://codeforces.com/blog/entry/48987
Problem  :  https://www.spoj.com/problems/MATCHING/


#include<bits/stdc++.h>
using namespace std;
struct BipartiteMatcher{
  vector<vector<int>> G;
  vector<int> L, R, Viz;
 
  BipartiteMatcher(int n, int m) :
  G(n), L(n, -1), R(m, -1), Viz(n) {}
 
  void AddEdge(int a, int b) {
    G[a].push_back(b);
  }
  
  bool Match(int node) {
    if (Viz[node])
      return false;
    Viz[node] = true;
    
    for (auto vec : G[node]) {
      if (R[vec] == -1) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    for (auto vec : G[node]) {
      if (Match(R[vec])) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    return false;
  }
  
  int Solve() {
    int ok = true;
    while (ok--) {
      fill(Viz.begin(), Viz.end(), 0);
      for (int i = 0; i < (int)L.size(); ++i)
        if (L[i] == -1)
          ok |= Match(i);
    }
    
    int ret = 0;
    for (int i = 0; i < L.size(); ++i)
      ret += (L[i] != -1);
    return ret;
  }
};
int main()
{
	int n,m,cnt;cin>>n>>m>>cnt;
	BipartiteMatcher b(n,m);
	for(int i=0;i<cnt;i++)
	{
		int u,v;cin>>u>>v;
		b.AddEdge(u-1,v-1);
	}
	cout<<b.Solve()<<endl;
}
	
