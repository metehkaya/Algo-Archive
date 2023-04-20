#include <bits/stdc++.h>
#define maxn 200001
#define pb push_back
using namespace std;

int n;
int ans[maxn];
vector<int> adj[maxn];

int dfs(int u) {
	ans[u] = 1;
	for( int i = 0 ; i < (int) adj[u].size() ; i++ ) {
		int v = adj[u][i];
		ans[u] += dfs(v);
	}
	return ans[u];
}

int main() {
	scanf("%d",&n);
	for( int i = 2 , x ; i <= n ; i++ ) {
		scanf("%d",&x);
		adj[x].pb(i);
	}
	dfs(1);
	for( int i = 1 ; i <= n ; i++ )
		printf("%d ",--ans[i]);
	return 0;
}