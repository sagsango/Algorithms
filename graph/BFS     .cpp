https://www.youtube.com/watch?v=KiCBXu4P-2Y&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=5
Shortest Path 
BFS
DP
Topological Short
BFS In Grid using queue : Think what data structure you will use and how ?
Make Grath from Given Grid or Given conditions 
Adjencancy List or Adjencency Matrix => Dense or Sparse


   /*
     Also Can Make a Par[] array for parent 
   */
    vvi G(N);
    vi level(N,-1);
    vb vis(N,0);
 
	queue<int>q;
	q.push(1);
	level[1]=0;
	vis[1]=1;
	while(q.size())
	{
		int u=q.front();q.pop();
		for(auto v:G[u])
		{
			if(!vis[v]) 
			{
				q.push(v);
				level[v]=level[u]+1;
				vis[v]=1;
			}
		}
	}
	cout<<level[n]<<endl;
