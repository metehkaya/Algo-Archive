#include <bits/stdc++.h>
#define maxn 200001
#define pb push_back
using namespace std;

int n;
int sz[maxn];
vector<int> adj[maxn];

int dfs(int u , int dad) {
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v != dad)
			sz[u] += dfs(v,u);
	}
	return ++sz[u];
}

int findRoot() {
	int nsz = n;
	int root = 1;
	int minSz = sz[root];
	int limit = (nsz+1) / 2;
	for( int u = 2 ; u <= n ; u++ )
		if(sz[u] >= limit && sz[u] < minSz) {
			root = u;
			minSz = sz[u];
		}
	return root;
}

int main() {
	scanf("%d",&n);
	for( int i = 1 , u,v ; i < n ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0);
	printf("%d\n",findRoot());
	return 0;
}
