#include <bits/stdc++.h>
#define maxn 200001
#define pb push_back
using namespace std;
typedef long long LL;

int n;
int sz[maxn];
LL ans[maxn];
vector<int> adj[maxn];

int dfs1(int u , int dad , int lvl) {
	sz[u] = 1;
	ans[1] += lvl;
	for( int i = 0 ; i < (int) adj[u].size() ; i++ ) {
		int v = adj[u][i];
		if(v != dad)
			sz[u] += dfs1(v,u,lvl+1);
	}
	return sz[u];
}

void dfs2(int u , int dad) {
	for( int i = 0 ; i < (int) adj[u].size() ; i++ ) {
		int v = adj[u][i];
		if(v == dad)
			continue;
		ans[v] = ans[u] - sz[v] + (n - sz[v]);
		dfs2(v,u);
	}
}

int main() {
	scanf("%d",&n);
	for( int i = 1 , u , v ; i < n ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(1,0,0);
	dfs2(1,0);
	for( int i = 1 ; i <= n ; i++ )
		printf("%lld ",ans[i]);
	return 0;
}