#include <bits/stdc++.h>
#define maxk 18
#define maxn 200001
#define pb push_back
using namespace std;

int n,m;
int lvl[maxn];
int par[maxn][maxk];
vector<int> adj[maxn];

void dfs(int u , int dad) {
	par[u][0] = dad;
	lvl[u] = lvl[dad] + 1;
	for( int i = 1 ; i < maxk ; i++ )
		par[u][i] = par[par[u][i-1]][i-1];
	for( int i = 0 ; i < (int) adj[u].size() ; i++ )
		if( adj[u][i] != dad )
			dfs(adj[u][i],u);
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 , u , v ; i < n ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0);
	for( int i = 0 , u , v ; i < m ; i++ ) {
		scanf("%d%d",&u,&v);
		int tu = u , tv = v;
		if(lvl[u] < lvl[v])
			swap(u,v);
		int diff = lvl[u] - lvl[v];
		for( int k = 0 ; k < maxk ; k++ )
			if(diff & (1<<k))
				u = par[u][k];
		int lca = 1;
		if(u == v)
			lca = u;
		else
			for( int k = maxk-1 ; k >= 0 ; k-- ) {
				int u2 = par[u][k];
				int v2 = par[v][k];
				if(u2 == 0)
					continue;
				if(u2 == v2)
					lca = u2;
				else
					u = u2 , v = v2;
			}
		printf("%d\n",lvl[tu]+lvl[tv]-2*lvl[lca]);
	}
	return 0;
}