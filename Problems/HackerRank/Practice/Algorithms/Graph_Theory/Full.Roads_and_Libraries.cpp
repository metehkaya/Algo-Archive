#include <bits/stdc++.h>
#define maxn 100003
#define pb push_back
using namespace std;
typedef long long LL;

LL ans,cnt;
int T,n,m,lib,road,tc;
int mark[maxn];
vector<int> adj[maxn];

void reset() {
	ans = 0;
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
}

void dfs(int node) {
	cnt++;
	mark[node] = tc;
	for( int i = 0 ; i < adj[node].size() ; i++ )
		if(mark[adj[node][i]] != tc)
			dfs(adj[node][i]);
}

int main() {
	scanf("%d",&T);
	for( tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d%d%d",&n,&m,&lib,&road);
		for( int i = 0 , x , y ; i < m ; i++ ) {
			scanf("%d%d",&x,&y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		for( int i = 1 ; i <= n ; i++ )
			if(mark[i] != tc) {
				cnt = 0;
				dfs(i);
				ans += min(cnt*lib,lib+(cnt-1)*road);
			}
		printf("%lld\n",ans);
	}
	return 0;
}
