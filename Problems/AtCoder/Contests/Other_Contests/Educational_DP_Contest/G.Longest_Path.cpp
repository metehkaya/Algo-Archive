#include <bits/stdc++.h>
#define maxn 100001
#define pb push_back
using namespace std;

int n,m,ans;
int dp[maxn];
vector<int> adj[maxn];

int dfs(int node) {
	if(dp[node])
		return dp[node];
	for( int i = 0 ; i < (int) adj[node].size() ; i++ )
		dp[node] = max( dp[node] , dfs( adj[node][i] ) );
	return ++dp[node];
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < m ; i++ ) {
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
	}
	for( int i = 1 ; i <= n ; i++ )
		ans = max( ans , dfs(i) );
	printf("%d\n",ans-1);
	return 0;
}
