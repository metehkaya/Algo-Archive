#include <bits/stdc++.h>
#define maxk 17
#define maxn 100003
#define pb push_back
using namespace std;

int n,m,root;
int lvl[maxn];
int par[maxn][maxk];
vector<int> adj[maxn];

void dfs(int u , int dad) {
	lvl[u] = lvl[dad]+1;
	par[u][0] = dad;
	for( int k = 1 ; k < maxk ; k++ )
		par[u][k] = par[par[u][k-1]][k-1];
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v != dad)
			dfs(v,u);
	}
}

int lca(int u , int v) {
	if(lvl[u] < lvl[v])
		swap(u,v);
	int diff = lvl[u]-lvl[v];
	for( int k = 0 ; k < maxk ; k++ )
		if(diff & (1<<k))
			u = par[u][k];
	if(u == v)
		return u;
	int ans = root;
	for( int k = maxk-1 ; k >= 0 ; k-- ) {
		int dad_u = par[u][k];
		int dad_v = par[v][k];
		if(!dad_u)
			continue;
		if(dad_u == dad_v)
			ans = dad_u;
		else
			u = dad_u , v = dad_v;
	}
	return ans;
}

int main() {
	scanf("%d%d%d",&n,&m,&root);
	for( int i = 1 , u,v ; i < n ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(root,0);
	for( int i = 0 , u,v ; i < m ; i++ ) {
		scanf("%d%d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}
