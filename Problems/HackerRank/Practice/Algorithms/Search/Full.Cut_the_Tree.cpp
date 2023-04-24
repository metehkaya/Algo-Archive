#include <bits/stdc++.h>
#define maxn 100001
#define pb push_back
using namespace std;

int n,ans;
int sum[maxn];
vector<int> adj[maxn];

int dfs(int node, int dad) {
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i];
		if( to != dad )
			sum[node] += dfs(to, node);
	}
	return sum[node];
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&sum[i]);
	for( int i = 1 , x,y ; i < n ; i++ ) {
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,0);
	ans = sum[1];
	for( int i = 2 ; i <= n ; i++ )
		ans = min( ans , abs(sum[1]-2*sum[i]) );
	printf("%d\n",ans);
	return 0;
}
