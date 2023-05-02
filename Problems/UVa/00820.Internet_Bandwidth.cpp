#include <bits/stdc++.h>
#define maxn 103
#define pb push_back
using namespace std;

int n,m,src,sink;
int bfs_cnt,ans;
int mark[maxn];
int dist[maxn];
int adjId[maxn];
int G[maxn][maxn];
bool var[maxn][maxn];
vector<int> adj[maxn];

bool bfs(int src , int sink) {
	queue<int> Q;
	Q.push(src);
	dist[src] = 0;
	mark[src] = bfs_cnt;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		if(u == sink)
			return true;
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			if(mark[v] == bfs_cnt || !G[u][v])
				continue;
			Q.push(v);
			mark[v] = bfs_cnt;
			dist[v] = dist[u] + 1;
		}
	}
	return false;
}

int dfs(int u , int sink , int p) {
	if(u == sink)
		return p;
	int deg = adj[u].size();
	while(adjId[u] < deg) {
		int v = adj[u][adjId[u]];
		if(mark[v] == bfs_cnt && G[u][v] > 0 && dist[v] == dist[u]+1) {
			int w = min(p,G[u][v]);
			w = dfs(v,sink,w);
			if(w) {
				G[u][v] -= w;
				G[v][u] += w;
				return w;
			}
		}
		adjId[u]++;
	}
	return 0;
}

void reset() {
	bfs_cnt = ans = 0;
	for( int i = 1 ; i <= n ; i++ ) {
		mark[i] = 0;
		adj[i].clear();
		for( int j = 1 ; j <= n ; j++ )
			G[i][j] = var[i][j] = 0;
	}
}

int main() {
	for( int tc = 1 ; true ; tc++ ) {
		scanf("%d",&n);
		if(n == 0)
			break;
		reset();
		scanf("%d%d%d",&src,&sink,&m);
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
			bfs_cnt++;
			bool exists = bfs(src,sink);
			if(!exists)
				break;
			for( int i = 1 ; i <= n ; i++ )
				adjId[i] = 0;
			while(true) {
				int path = dfs(src,sink,INT_MAX);
				if(!path)
					break;
				ans += path;
			}
		}
		printf("Network %d\n",tc);
		printf("The bandwidth is %d.\n",ans);
		puts("");
	}
	return 0;
}
