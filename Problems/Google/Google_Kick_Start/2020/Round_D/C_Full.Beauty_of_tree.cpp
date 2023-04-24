#include <bits/stdc++.h>
#define maxn 500001
#define pb push_back
using namespace std;
typedef long long LL;

int T,n,a,b;
int ar[maxn];
int cnt[maxn];
int chain[maxn];
LL ans,totA;
LL total[maxn];
vector<int> adj[maxn];

void dfs2(int u , int lvl) {
	total[lvl%b] += cnt[u];
	ans += (LL) n*(lvl/b+1) + totA - total[lvl%b];
	for( int i = 0 ; i < (int) adj[u].size() ; i++ )
		dfs2(adj[u][i],lvl+1);
	total[lvl%b] -= cnt[u];
}

void dfs(int u , int lvl) {
	totA += lvl/a+1;
	chain[lvl] = u;
	cnt[u] = 1;
	for( int i = 0 ; i < (int) adj[u].size() ; i++ )
		dfs(adj[u][i],lvl+1);
	if(lvl >= a)
		cnt[chain[lvl-a]] += cnt[u];
}

void reset() {
	ans = totA = 0;
	for( int i = 1 ; i <= n ; i++ ) {
		cnt[i] = 0;
		adj[i].clear();
	}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d%d",&n,&a,&b);
		for( int i = 2 , dad ; i <= n ; i++ ) {
			scanf("%d",&dad);
			adj[dad].pb(i);
		}
		dfs(1,0);
		dfs2(1,0);
		LL allp = (LL) n*n;
		printf("Case #%d: %.10lf\n",tc,(double)ans/allp);
	}
	return 0;
}
