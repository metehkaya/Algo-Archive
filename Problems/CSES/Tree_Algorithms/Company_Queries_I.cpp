#include <bits/stdc++.h>
#define maxk 18
#define maxn 200001
#define pb push_back
using namespace std;

int n,m;
int par[maxn][maxk];
vector<int> adj[maxn];

void dfs(int u , int dad) {
	par[u][0] = dad;
	for( int i = 1 ; i < maxk ; i++ )
		par[u][i] = par[par[u][i-1]][i-1];
	for( int i = 0 ; i < (int) adj[u].size() ; i++ )
		dfs(adj[u][i],u);
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 2 , x ; i <= n ; i++ ) {
		scanf("%d",&x);
		adj[x].pb(i);
	}
	dfs(1,0);
	for( int i = 0 , u , d ; i < m ; i++ ) {
		scanf("%d%d",&u,&d);
		for( int k = 0 ; k < maxk ; k++ )
			if(d & (1<<k))
				u = par[u][k];
		if(u == 0)
			u = -1;
		printf("%d\n",u);
	}
	return 0;
}