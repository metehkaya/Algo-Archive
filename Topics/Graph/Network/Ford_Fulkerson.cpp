#include <bits/stdc++.h>
#define maxn 103
#define pb push_back
using namespace std;

int n,m,dfs_cnt,ans;
int mark[maxn];
int G[maxn][maxn];
bool var[maxn][maxn];
vector<int> adj[maxn];

int dfs(int u , int sink , int p) {
	mark[u] = dfs_cnt;
	if(u == sink)
		return p;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(mark[v] == dfs_cnt || !G[u][v])
			continue;
		int w = min(p,G[u][v]);
		w = dfs(v,sink,w);
		if(w) {
			G[u][v] -= w;
			G[v][u] += w;
			return w;
		}
	}
	return 0;
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x,y,z ; i < m ; i++ ) {
		scanf("%d%d%d",&x,&y,&z);
		if(!var[x][y]) {
			adj[x].pb(y);
			adj[y].pb(x);
		}
		G[x][y] += z;
		G[y][x] += z;
		var[x][y] = var[y][x] = true;
	}
	while(true) {
		dfs_cnt++;
		int path = dfs(1,n,INT_MAX);
		if(!path)
			break;
		ans += path;
	}
	printf("%d\n",ans);
	return 0;
}
