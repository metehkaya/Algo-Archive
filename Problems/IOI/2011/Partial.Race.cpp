#include <bits/stdc++.h>
#include "race.h"
#define fi first
#define se second
#define maxn 1000
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n,k,ans;
vector<pi> adj[maxn];

void dfs(int u , int dad , int d , int dist) {
	if(dist == k)
		ans = min(ans,d);
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i].fi;
		int dist2 = dist + adj[u][i].se;
		if(v != dad)
			dfs(v,u,d+1,dist2);
	}
}

int best_path(int N, int K, int e[][2], int c[]) {
	n = N;
	k = K;
	ans = n+1;
	for( int i = 0 ; i < n-1 ; i++ ) {
		int u = e[i][0];
		int v = e[i][1];
		int d = c[i];
		adj[u].pb(pi(v,d));
		adj[v].pb(pi(u,d));
	}
	for( int i = 0 ; i < n ; i++ )
		dfs(i,-1,0,0);
	return (ans < n) ? ans : -1;
}
