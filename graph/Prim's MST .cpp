Use priority_queue for primes too like Diskta Algorithm
Doubt:Tree formed by Disktra and Primes has same total waight??


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
int n,m,u,v,w,q,g,l,r,ans=0;

int32_t main()
{
	IOS
	//taking no of verticies ans no of edges as input
	int n,m;cin>>n>>m;
	//initialise a cont of evey vetex as inf
	//###########cost[u] : minimum cost to reach u from some other neghibour vertex############
	vi cost(n+1,inf);
	//insert all the verticies with their respective cost
	set<ii>s;
	for(int i=1;i<=n;i++)
	{
		s.insert({cost[i],i});
	}
	//taking graph as input 
	vvii G(n+1);
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		G[u].pb({v,w});
		G[v].pb({u,w});
	}
	//initialising ans by -inf which is balance cost of first choosing verticies
	ans=-inf;
	//untill there left any verticies in set we have to extact greedly
	while(s.size())
	{
		//taking the verticies having least cost and erase it from the set
		v=s.begin()->second;
		ans+=cost[v];
		s.erase(s.begin());
		//Now we have to make all the adj verticies of v aviable to us by updating their cost
		for(auto it:G[v])
		{
			u=it.first,w=it.second;
			if( cost[u] > w )
			{
				//If the adj vecticies have already been taken no need to update
				auto it=s.find({cost[u],u});
				if(it!=s.end())
				{
					s.erase(it);
				    cost[u]=w;
				    s.insert({cost[u],u});
				}
				
			}
		}
	}
	cout<<ans<<endl;
}
		
	
	
	
	
	
		
	

		
