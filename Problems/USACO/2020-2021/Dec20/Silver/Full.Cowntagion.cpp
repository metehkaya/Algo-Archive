#include <bits/stdc++.h>
#define maxn 100003
#define pb push_back
using namespace std;
typedef long long LL;

int n;
LL dp[maxn];
int sz[maxn];
int lvl[maxn];
LL sumlvl[maxn];
vector<int> adj[maxn];

int f(int x) {
	int k = 1 , cnt = 0;
	while(k < x) {
		cnt++;
		k *= 2;
	}
	return cnt;
}

LL dfs(int u , int dad) {
	sz[u] = 1;
	lvl[u] = lvl[dad]+1;
	sumlvl[u] = lvl[u];
	LL sum = 0;
	int nch = 0;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v != dad) {
			nch++;
			sum += dfs(v,u);
			sz[u] += sz[v];
			sumlvl[u] += sumlvl[v];
		}
	}
	dp[u] = min( f(sz[u]) + (sumlvl[u] - (LL)sz[u]*lvl[u]) , f(nch+1)+sum+nch );
	return dp[u];
}

int main() {
	scanf("%d",&n);
	for( int i = 1 , u,v ; i < n ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	printf("%lld\n",dfs(1,0));
	return 0;
}
