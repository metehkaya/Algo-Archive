#include <bits/stdc++.h>
#include "dreaming.h"
#define fi first
#define se second
#define maxn 100000
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int tDist,tDist2;
bool mark[maxn];
pi best[maxn][2];
vector<pi> adj[maxn];

void dfs2(int u , int dad , int up) {
	tDist = min(tDist,max(best[u][0].fi,up));
	tDist2 = max(tDist2,max(best[u][0].fi,0)+up);
	tDist2 = max(tDist2,max(best[u][0].fi,0)+max(best[u][1].fi,0));
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i].fi;
		int e = adj[u][i].se;
		if(v == dad)
			continue;
		if(v == best[u][0].se)
			dfs2(v,u,max(up,max(best[u][1].fi,0))+e);
		else
			dfs2(v,u,max(up,best[u][0].fi)+e);
	}
}

int dfs1(int u , int dad) {
	mark[u] = true;
	int deg = adj[u].size();
	best[u][0] = best[u][1] = pi(-1,-1);
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i].fi;
		int e = adj[u][i].se;
		if(v == dad)
			continue;
		int len = dfs1(v,u) + e;
		if(len >= best[u][0].fi) {
			best[u][1] = best[u][0];
			best[u][0] = pi(len,v);
		}
		else if(len >= best[u][1].fi)
			best[u][1] = pi(len,v);
	}
	return max(best[u][0].fi,0);
}

int travelTime(int n, int m, int l, int a[], int b[], int t[]) {
	for( int i = 0 ; i < m ; i++ ) {
		adj[a[i]].pb(pi(b[i],t[i]));
		adj[b[i]].pb(pi(a[i],t[i]));
	}
	memset(mark,false,sizeof(mark));
	vector<int> dists;
	tDist2 = 0;
	for( int i = 0 ; i < n ; i++ )
		if(!mark[i]) {
			dfs1(i,-1);
			tDist = INT_MAX;
			dfs2(i,-1,0);
			dists.pb(tDist);
		}
	int ans;
	int k = dists.size();
	if(k == 1)
		ans = tDist2;
	else if(k == 2)
		ans = max(dists[0]+dists[1]+l,tDist2);
	else {
		sort(dists.begin(),dists.end());
		ans = max(dists[k-1]+dists[k-2]+l,dists[k-2]+dists[k-3]+2*l);
		ans = max(ans,tDist2);
	}
	return ans;
}
