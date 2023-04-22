#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int T,n;
int ar[51];
int sum[51];
vector<int> adj[51];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
}

int dfs(int u , int dad) {
	sum[u] = 0;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v != dad)
			sum[u] = max(sum[u],dfs(v,u));
	}
	sum[u] += ar[u];
	return sum[u];
}

int solve() {
	dfs(1,0);
	vector<int> vec;
	int k = adj[1].size();
	for( int i = 0 ; i < k ; i++ ) {
		int v = adj[1][i];
		vec.pb(sum[v]);
	}
	int ans = ar[1];
	if(k >= 1) {
		sort(vec.begin(),vec.end());
		ans += vec[k-1];
		if(k >= 2)
			ans += vec[k-2];
	}
	return ans;
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		for( int i = 1 , u,v ; i < n ; i++ ) {
			scanf("%d%d",&u,&v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int ans = solve();
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
