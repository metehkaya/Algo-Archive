#include <bits/stdc++.h>
#include "race.h"
#define fi first
#define se second
#define maxn 200000
#define maxk 1000001
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n,k,ans;
int sz[maxn];
int dist[maxn];
int depth[maxn];
bool mark[maxn];
int minDepth[maxk];
vector<int> nodes;
vector<pi> adj[maxn];

int dfs(int u , int dad , int de , int di) {
	sz[u] = 1;
	dist[u] = di;
	depth[u] = de;
	nodes.pb(u);
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i].fi;
		int vdi = di + adj[u][i].se;
		if(v != dad && !mark[v])
			sz[u] += dfs(v,u,de+1,vdi);
	}
	return sz[u];
}

void Dfs(int u) {
	nodes.clear();
	dfs(u,-1,0,0);
}

int findRoot() {
	int nsz = nodes.size();
	int root = nodes[0];
	int minSz = sz[root];
	int limit = (nsz+1) / 2;
	for( int i = 1 ; i < nsz ; i++ ) {
		int u = nodes[i];
		if(sz[u] >= limit && sz[u] < minSz) {
			root = u;
			minSz = sz[u];
		}
	}
	return root;
}

void solve(int u) {
	Dfs(u);
	u = findRoot();
	mark[u] = true;
	int deg = adj[u].size();
	vector<int> rem;
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i].fi;
		int d = adj[u][i].se;
		if(!mark[v]) {
			Dfs(v);
			vector<pi> upd;
			int nsz = nodes.size();
			for( int j = 0 ; j < nsz ; j++ ) {
				int w = nodes[j];
				int wDist = dist[w] + d;
				int wDepth = depth[w] + 1;
				if(wDist <= k) {
					rem.pb(wDist);
					upd.pb(pi(wDist,wDepth));
					int remDist = k-wDist;
					if(minDepth[remDist] != -1)
						ans = min(ans,minDepth[remDist]+wDepth);
				}
				if(wDist == k)
					ans = min(ans,wDepth);
			}
			int nupd = upd.size();
			for( int j = 0 ; j < nupd ; j++ ) {
				int key = upd[j].fi;
				int val = upd[j].se;
				if(minDepth[key] == -1 || val < minDepth[key])
					minDepth[key] = val;
			}
		}
	}
	int r = rem.size();
	for( int i = 0 ; i < r ; i++ )
		minDepth[rem[i]] = -1;
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i].fi;
		if(!mark[v])
			solve(v);
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
	memset(minDepth,-1,sizeof(minDepth));
	solve(0);
	return (ans < n) ? ans : -1;
}
