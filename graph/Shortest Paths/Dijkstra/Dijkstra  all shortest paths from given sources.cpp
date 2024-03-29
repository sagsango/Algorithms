-> Note : graph my be directed or undirected 
        : goes very node +  check every edge [ twise in undirected and once in directed] + maintain sorted edges
        : O( v + e * log(e) )

Topological Short, Dinemic Programming ,Dijkstra  : 
https://www.youtube.com/watch?v=TXkDpqjDMHA&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=7
Shortest Path or Longest Path => DP / - w[i]


This algorithm is a single source shortest path (from one source to any other vertices). 
Pay attention that you can't have edges with negative weight.

//also always maintain parent array
	
Using std :: priority_queue (better):  O(n*log(n))
bool vis[MAXN];
int d[MAXN];
vector<int>par(MAXN);
vector<vector<int,int>>G;
void dijkstra(int s){
	fill(d,d + n, inf);
	fill(mark, mark + n, false);
	d[s] = 0;
	par[s]=-1;
	priority_queue<pair<int,int>,vector<pair<int,int> >, less<pair<int,int> > > pq;
	pq.push({d[s], s});
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		if(vis[u])//has  relaxed its neighbours
			continue;
		vis[u] = true;
		for(auto it : G[u]) //adj[v][i] = pair(vertex, weight)
		{
			int v = it.first;
			int w = it.secon;
			if( vis[v] )continue;//No need to check because it has already min distance
			if( d[v] > w + d[u] )
			{
				par[v]=u;
				d[v] = d[u] + w;
				pq.push({d[v],v});
			}
		}

	}
}	


queue QX , QY
push source S to QX
while one of the two queues is not empty:
    u = pop minimal distant node among the two queue heads
    for all edges e of form (u,v):
        if dist(v) > dist(u) + cost(e):
            dist(v) = dist(u) + cost(e);
            if cost(e) == X:
                QX.push(dist(v),v);
            else:
                QY.push(dist(v),v);
                

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.rbegin(),a.rend())
#define lb(a,b) lower_bound(a.begin(),a.end(),b)
#define ub(a,b) upper_bound(a.begin(),a.end(),b)
#define MOD ((int)(1e9+7))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define float long double
#define sqrt sqrtl
#define cbrt cbrtl
typedef vector<int> vi;
typedef vector<float> vf;
typedef pair<float,int> fi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<fi> vfi;
typedef vector<vi> vvi;
typedef vector<vf> vvf;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef priority_queue<int> pqi;
typedef priority_queue<ii> pqii;
typedef priority_queue<fi> pqfi;
typedef priority_queue <int, vector<int>, greater<int> > rpqi; 
typedef priority_queue <ii, vector<ii>, greater<ii> > rpqii; 
typedef priority_queue <fi, vector<fi>, greater<fi> > rpqfi; 


vector<int>dx={0,1,0,-1},dy={1,0,-1,0};
const int N=2e5+10;
int sum=0,mx=-1e18,mn=1e18,inf=1e18;
int n,m,u,v,w,q,g,l,r,ans,p;

int32_t main()
{
	IOS
	cin>>n>>m>>p;
	vi dis(n+1,inf);
	vi parent(n+1,-1);
	dis[p]=0;
	vb mark(n+1,false);
	vvii G(n+1);
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		G[u].pb({v,w});
		G[v].pb({u,w});
	}
	set<ii>s;s.insert({p,0});
	while( s.size() )
	{
		v=s.begin()->second;
		s.erase(s.begin());
		for(auto it:G[v])
		{
			u=it.first;w=it.second;
			if(dis[u] > dis[v] + w)
			{
				auto it=s.find({dis[u],u});
				if(it!=s.end())s.erase(it);
				dis[u]=dis[v]+w;
				s.insert({dis[u],u});
				parent[u]=v;
			}
		}
	}
}
		
		
	
	
	
	
		
	
}
		

