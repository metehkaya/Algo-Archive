#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100003
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,LL> piL;

LL sum,ans;
int n,k,r;
int par[maxn];
int edge[maxn];
bool var[maxn];
bool mark[maxn];
piL best;
vector<pii> adj[maxn];

void solve( int node , int dad , LL dist ) {
	if( var[node] )
		ans = min( ans , 2*sum - dist );
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i].fi;
		int len = adj[node][i].se;
		if( to != dad )
			solve(to, node, dist + len);
	}
}

void dfs( int node , int dad , LL dist ) {
	if( var[node] ) {
		if( dist > best.se ) {
			best.fi = node;
			best.se = dist;
		}
		int tmp = node;
		while(tmp != r && !mark[tmp]) {
			mark[tmp] = true;
			sum += edge[tmp];
			tmp = par[tmp];
		}
	}
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i].fi;
		int len = adj[node][i].se;
		if( to != dad ) {
			par[to] = node;
			edge[to] = len;
			dfs(to, node, dist + len);
		}
	}
}

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < k ; i++ ) {
		scanf("%d",&r);
		var[r] = true;
	}
	for( int i = 1 , x,y,z ; i < n ; i++ ) {
		scanf("%d%d%d",&x,&y,&z);
		adj[x].pb(pii(y,z));
		adj[y].pb(pii(x,z));
	}
	dfs(r,0,0);
	ans = 2*sum;
	solve(best.fi,0,0);
	printf("%lld\n",ans);
	return 0;
}
