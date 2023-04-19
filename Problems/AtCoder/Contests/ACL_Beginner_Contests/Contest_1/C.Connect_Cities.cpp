#include <bits/stdc++.h>
#define maxn 100005
#define pb push_back
using namespace std;

int n,m,ans;
bool mark[maxn];
vector<int> adj[maxn];

void dfs(int u) {
	mark[u] = true;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(!mark[v])
			dfs(v);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , u,v ; i < m ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for( int i = 1 ; i <= n ; i++ )
		if(!mark[i]) {
			ans++;
			dfs(i);
		}
	printf("%d\n",--ans);
	return 0;
}
