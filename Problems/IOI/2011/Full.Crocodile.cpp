#include <bits/stdc++.h>
#include "crocodile.h"
#define fi first
#define se second
#define maxn 100000
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

struct datum {
	int u;
	LL dist;
	datum(int _u , LL _dist) {
		u = _u;
		dist = _dist;
	}
};

bool operator<(const datum& a , const datum& b) {
	return a.dist > b.dist;
}

bool mark[maxn];
LL dist[maxn][2];
vector<pi> adj[maxn];
priority_queue<datum> heap;

int travel_plan(int n, int m, int e[][2], int c[], int k, int p[]) {
	for( int i = 0 ; i < m ; i++ ) {
		int u = e[i][0];
		int v = e[i][1];
		int d = c[i];
		adj[u].pb(pi(v,d));
		adj[v].pb(pi(u,d));
	}
	for( int i = 0 ; i < n ; i++ ) {
		mark[i] = false;
		dist[i][0] = dist[i][1] = (1LL<<60);
	}
	for( int i = 0 ; i < k ; i++ ) {
		dist[p[i]][0] = 0;
		dist[p[i]][1] = 0;
		heap.push(datum(p[i],0));
	}
	while(!heap.empty()) {
		datum dt = heap.top();
		heap.pop();
		int u = dt.u;
		LL du = dt.dist;
		if(u == 0)
			break;
		if(mark[u])
			continue;
		mark[u] = true;
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i].fi;
			LL dv = du + adj[u][i].se;
			if(!mark[v]) {
				LL bef = dist[v][1];
				if(dv <= dist[v][0]) {
					dist[v][1] = dist[v][0];
					dist[v][0] = dv;
				}
				else if(dv <= dist[v][1])
					dist[v][1] = dv;
				if(dist[v][1] < bef)
					heap.push(datum(v,dist[v][1]));
			}
		}
	}
	return dist[0][1];
}
