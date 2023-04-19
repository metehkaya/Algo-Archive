#include <bits/stdc++.h>
#define maxn 200001
#define pb push_back
using namespace std;

int n,m,ans;
int a[maxn];
int best[maxn];
vector<int> adj[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&a[i]);
	for( int i = 0 , u,v ; i < m ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
	}
	ans = INT_MIN;
	for( int u = n ; u >= 1 ; u-- ) {
		best[u] = INT_MIN;
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			best[u] = max(best[u],best[v]);
		}
		if(deg)
			ans = max(ans,best[u]-a[u]);
		best[u] = max(best[u],a[u]);
	}
	printf("%d\n",ans);
	return 0;
}
