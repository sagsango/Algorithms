#include<bits/stdc++.h>
#define next NEXT
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
/*
//rank and path compression used
const int maxn = 1e6 + 5;
vector<int>par(maxn,-1);
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)) )    return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
//In the code above, for each root v, par[v] equals the negative of number of tools in that box.
	
*/
const int N=2e5+10;
vector<int>par(N);
vector<int>next(N);
int root(int u){return par[u] < 0 ? u : par[u]=root(par[u]);}
void merge(int u,int v)
{
	if( ( u = root(u) ) == ( v = root(v) ) )return;
	if(par[u] < par[v])swap(u,v);
	par[v]+=par[u];
	par[u]=v;
	
}
int32_t main()
{
	IOS
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		par[i]=-1;
		next[i]=i+1;
	}
	while(q--)
	{
		int t,u,v;cin>>t>>u>>v;
		switch(t)
		{
			case 1:
			merge(u,v);
			break;
			
			case 2:
			while(u<v)
			{
				merge(u,u+1);
				int temp=next[u];
				next[u]=v;
				u=temp;
			}
			break;
			
			case 3:
			cout<<( (root(u)==root(v)) ? "YES" : "NO" )<<endl;
			break;
		}
	}
}
			
			
	

	
