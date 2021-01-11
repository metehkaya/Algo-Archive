#include <bits/stdc++.h>
#include "garden.h"
#include "gardenlib.h"
#define fi first
#define se second
#define maxn 1000
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n,p;
vector<pi> adj[maxn];

bool dfs(int u , int last , int rem) {
	if(rem == 0)
		return (u == p);
	int deg = adj[u].size();
	bool ok = false;
	if(deg == 1)
		ok = dfs(adj[u][0].fi,adj[u][0].se,rem-1);
	else {
		if(last != adj[u][0].se)
			ok = dfs(adj[u][0].fi,adj[u][0].se,rem-1);
		else
			ok = dfs(adj[u][1].fi,adj[u][1].se,rem-1);
	}
	return ok;
}

void count_routes(int N, int m, int P, int e[][2], int q, int dist[]) {
	n = N;
	p = P;
	for( int i = 0 ; i < m ; i++ ) {
		int u = e[i][0];
		int v = e[i][1];
		if(adj[u].size() < 2)
			adj[u].pb(pi(v,i));
		if(adj[v].size() < 2)
			adj[v].pb(pi(u,i));
	}
	for( int tc = 0 ; tc < q ; tc++ ) {
		int d = dist[tc] , ans = 0;
		for( int i = 0 ; i < n ; i++ )
			ans += dfs(i,-1,d);
		answer(ans);
	}
}
