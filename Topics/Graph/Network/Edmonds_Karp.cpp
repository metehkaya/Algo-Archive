#include <bits/stdc++.h>
#define maxn 103
#define pb push_back
using namespace std;

int n,m,bfs_cnt,ans;
int par[maxn];
int mark[maxn];
int minEdge[maxn];
int G[maxn][maxn];
bool var[maxn][maxn];
vector<int> adj[maxn];

int bfs(int src , int sink) {
	queue<int> Q;
	Q.push(src);
	mark[src] = bfs_cnt;
	minEdge[src] = INT_MAX;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		if(u == sink)
			return minEdge[u];
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			if(mark[v] == bfs_cnt || !G[u][v])
				continue;
			Q.push(v);
			par[v] = u;
			mark[v] = bfs_cnt;
			minEdge[v] = min(minEdge[u],G[u][v]);
		}
	}
	return 0;
}

void edgeUpdate(int path) {
	int u = n;
	while(u != 1) {
		int p = par[u];
		G[p][u] -= path;
		G[u][p] += path;
		u = p;
	}
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
		bfs_cnt++;
		int path = bfs(1,n);
		if(!path)
			break;
		ans += path;
		edgeUpdate(path);
	}
	printf("%d\n",ans);
	return 0;
}
