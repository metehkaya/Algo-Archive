#include <bits/stdc++.h>
#define maxn 200001
#define pb push_back
using namespace std;

int n;
int dp[maxn][2];
vector<int> adj[maxn];

int dfs(int u , int dad , int k) {
	if(dp[u][k] != -1)
		return dp[u][k];
	dp[u][k] = 0;
	for( int i = 0 ; i < (int) adj[u].size() ; i++ ) {
		int v = adj[u][i];
		if(v != dad)
			dp[u][k] += dfs(v,u,1);
	}
	int all1 = dp[u][k];
	if(k == 1)
		for( int i = 0 ; i < (int) adj[u].size() ; i++ ) {
			int v = adj[u][i];
			if(v != dad)
				dp[u][k] = max( dp[u][k] , all1 - dp[v][1] + dfs(v,u,0) + 1 );
		}
	return dp[u][k];
}

int main() {
	scanf("%d",&n);
	for( int i = 1 , u , v ; i < n ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(1,0,1));
	return 0;
}