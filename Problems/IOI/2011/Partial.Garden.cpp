#include <bits/stdc++.h>
#include "garden.h"
#include "gardenlib.h"
#define maxk 30
#define maxn 150003
#define pb push_back
using namespace std;

int n;
int dp[maxn][2][maxk][2];
vector<int> adj[maxn];

void precalc() {
	memset(dp,-1,sizeof(dp));
	for( int u = 0 ; u < n ; u++ ) {
		int v = adj[u][0];
		dp[u][1][0][0] = v;
		if(adj[v].size() == 1)
			dp[u][1][0][1] = 1;
		else
			dp[u][1][0][1] = (adj[v][0] != u);
		if(adj[u].size() == 2) {
			v = adj[u][1];
			dp[u][0][0][0] = v;
			if(adj[v].size() == 1)
				dp[u][0][0][1] = 1;
			else
				dp[u][0][0][1] = (adj[v][0] != u);
		}
	}
	for( int k = 1 ; k < maxk ; k++ )
		for( int u = 0 ; u < n ; u++ )
			for( int st = 0 ; st < 2 ; st++ )
				if(dp[u][st][k-1][0] != -1) {
					int v = dp[u][st][k-1][0];
					int st2 = dp[u][st][k-1][1];
					dp[u][st][k][0] = dp[v][st2][k-1][0];
					dp[u][st][k][1] = dp[v][st2][k-1][1];
				}
}

int solve(int u , int d) {
	int st = 1;
	for( int i = maxk-1 ; i >= 0 ; i-- )
		if(d & (1<<i)) {
			int v = dp[u][st][i][0];
			int stv = dp[u][st][i][1];
			u = v;
			st = stv;
		}
	return u;
}

void count_routes(int N, int m, int p, int e[][2], int q, int dist[]) {
	n = N;
	for( int i = 0 ; i < m ; i++ ) {
		int u = e[i][0];
		int v = e[i][1];
		if(adj[u].size() < 2)
			adj[u].pb(v);
		if(adj[v].size() < 2)
			adj[v].pb(u);
	}
	precalc();
	for( int tc = 0 ; tc < q ; tc++ ) {
		int d = dist[tc] , ans = 0;
		for( int i = 0 ; i < n ; i++ )
			ans += (solve(i,d) == p);
		answer(ans);
	}
}
