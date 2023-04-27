#include <bits/stdc++.h>
#include "traffic.h"
#define maxn 1000000
#define pb push_back
using namespace std;
typedef long long LL;

int ar[maxn];
LL sum[maxn];
LL ans[maxn];
vector<int> adj[maxn];

LL dfs(int u , int dad , int d) {
	sum[u] = ar[u];
	ans[0] += (LL) d * ar[u];
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v == dad)
			continue;
		sum[u] += dfs(v,u,d+1);
	}
	return sum[u];
}

void solve(int u , int dad) {
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v == dad)
			continue;
		ans[v] = ans[u] + sum[0] - 2*sum[v];
		solve(v,u);
	}
}

int LocateCentre(int n, int P[], int S[], int D[]) {
	for( int i = 0 ; i < n ; i++ )
		ar[i] = P[i];
	for( int i = 0 ; i < n-1 ; i++ ) {
		int u = S[i] , v = D[i];
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0,-1,0);
	solve(0,-1);
	int best = 0;
	for( int i = 1 ; i < n ; i++ )
		if(ans[i] < ans[best])
			best = i;
	return best;
}
