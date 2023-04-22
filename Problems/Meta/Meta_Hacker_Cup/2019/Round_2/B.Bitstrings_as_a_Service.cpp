#include <bits/stdc++.h>
#define maxn 4001
#define pb push_back
using namespace std;

int T,n,m,g;
int dp[maxn];
bool ans[maxn];
bool mark[maxn];
vector<int> adj[maxn];
vector<int> group[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	memset(dp,-1,sizeof(dp));
	memset(ans,false,sizeof(ans));
	memset(mark,false,sizeof(mark));
	for( int i = 1 ; i <= g ; i++ )
		group[i].clear();
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
	g = 0;
}

void dfs(int u , int g) {
	group[g].pb(u);
	mark[u] = true;
	for( int i = 0 ; i < adj[u].size() ; i++ ) {
		int v = adj[u][i];
		if(!mark[v])
			dfs(v,g);
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&m);
		for( int i = 0 , l,r ; i < m ; i++ ) {
			scanf("%d%d",&l,&r);
			for( int j = l ; j <= r ; j++ )
				adj[j].pb(l+r-j);
		}
		for( int i = 1 ; i <= n ; i++ )
			if(!mark[i])
				dfs(i,++g);
		dp[0] = 0;
		for( int i = 1 ; i <= g ; i++ ) {
			int sz = group[i].size();
			for( int j = n-sz ; j >= 0 ; j-- )
				if(dp[j] != -1 && dp[j+sz] == -1)
					dp[j+sz] = i;
		}
		int total = -1;
		for( int i = n/2 ; i >= 0 ; i-- )
			if(dp[i] != -1) {
				total = i;
				break;
			}
		while(total) {
			int id = dp[total];
			int sz = group[id].size();
			for( int i = 0 ; i < sz ; i++ )
				ans[group[id][i]] = true;
			total -= sz;
		}
		printf("Case #%d: ",tc);
		for( int i = 1 ; i <= n ; i++ )
			printf("%d",ans[i]);
		puts("");
	}
	return 0;
}
