#include <bits/stdc++.h>
#define maxn 2501
#define pb push_back
using namespace std;

int n,m,ans;
int dist[maxn];
vector<int> adj[maxn];

void bfs(int root , int forbid) {
	queue<int> Q;
	memset(dist,-1,sizeof(dist));
	Q.push(root);
	dist[root] = 1;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		if(u == forbid)
			return;
		int deg = (int) adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			if(dist[v] != -1)
				continue;
			if(u == root && v == forbid)
				continue;
			Q.push(v);
			dist[v] = dist[u]+1;			
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , u,v ; i < m ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ans = n+1;
	for( int i = 1 ; i <= n ; i++ ) {
		int deg = (int) adj[i].size();
		for( int j = 0 ; j < deg ; j++ ) {
			int v = adj[i][j];
			bfs(i,v);
			if(dist[v] != -1)
				ans = min(ans,dist[v]);
		}
	}
	if(ans == n+1)
		ans = -1;
	printf("%d\n",ans);
	return 0;
}