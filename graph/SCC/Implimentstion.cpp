//source code   :   https://cp-algorithms.com/graph/strongly-connected-components.html
vector < vector<int> > g, gr;
vector<bool> used;
vector<int> order, component;

/* Note Interchainging g and gr between dfs1 and df2 works fine */
void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}

void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

int main() {
	int n , m ;
	cin >> n >> m;
	g=vector<vector<int>>(n);
	gr=vector<vector<int>>(n);
	used=vector<bool>(n);
	component.clear();
	order.clear();

	for (int i = 0 ;i < m;i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back (b);
		gr[b].push_back (a);
	}

	used.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);
	used.assign (n, false);

	// visit last to first : topological order
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i]; 
		if (!used[v]) {
			dfs2 (v);
			... printing next component ...
				component.clear();
		}
	}
}
