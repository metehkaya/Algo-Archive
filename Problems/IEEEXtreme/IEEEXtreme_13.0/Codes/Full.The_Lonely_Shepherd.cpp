#include <bits/stdc++.h>
#define maxn 100001
#define pb push_back
using namespace std;

int n,k;
bool var[maxn];
vector<int> adj[maxn];

void dfsFlip(int node, int dad, bool add) {
	var[node] = add;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i];
		if( to != dad )
			dfsFlip(to, node, add);
	}
}

void printFlip() {
	for( int i = 1 ; i <= n ; i++ )
		if(var[i])
			printf("flip %d\n", i);
}

int dfs(int node, int dad) {
	int cnt = 1;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i];
		if( to != dad )
			cnt += dfs(to,node);
	}
	if( cnt == k ) {
		dfsFlip(node, dad, true);
		printFlip();
		printf("cut %d %d\n", node, dad);
		exit(0);
	}
	else if( cnt == n-k ) {
		for( int i = 1 ; i <= n ; i++ )
			var[i] = true;
		dfsFlip(node, dad, false);
		printFlip();
		printf("cut %d %d\n", node, dad);
		exit(0);
	}
	return cnt;
}

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 1 , x,y ; i < n ; i++ ) {
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,0);
	puts("-1");
	return 0;
}
