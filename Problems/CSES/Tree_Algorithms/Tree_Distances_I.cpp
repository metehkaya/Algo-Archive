#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200001
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;

int n;
int ans[maxn];
pii best[maxn];
vector<int> adj[maxn];

int dfs(int u , int dad) {
	best[u] = pii( pi(0,u) , pi(-1,-1) );
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v == dad)
			continue;
		int len = dfs(v,u);
		if(len >= best[u].fi.fi) {
			best[u].se = best[u].fi;
			best[u].fi = pi(len,v);
		}
		else if(len >= best[u].se.fi)
			best[u].se = pi(len,v);
	}
	return best[u].fi.fi+1;
}

void solve(int u , int dad , int other) {
	ans[u] = max(other,best[u].fi.fi);
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v == dad)
			continue;
		int mx = other+1;
		if(v != best[u].fi.se)
			mx = max(mx,best[u].fi.fi+1);
		else if(best[u].se.se != -1)
			mx = max(mx,best[u].se.fi+1);
		solve(v,u,mx);
	}
}

int main() {
	scanf("%d",&n);
	for( int i = 1 , u,v ; i < n ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0);
	solve(1,0,0);
	for( int i = 1 ; i <= n ; i++ )
		printf("%d ",ans[i]);
	puts("");
	return 0;
}
