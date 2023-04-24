#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100003
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,LL> pil;

int T,n;
int ar[maxn];
int dad[maxn];
vector<int> adj[maxn];

void reset() {
	for( int i = 0 ; i <= n ; i++ )
		adj[i].clear();
}

pil dfs(int u , int mx) {
	mx = max(mx,ar[u]);
	int deg = adj[u].size();
	if(deg == 0)
		return pil(mx,mx);
	else if(deg == 1)
		return dfs(adj[u][0],mx);
	LL sum = 0;
	int mn = INT_MAX;
	for( int i = 0 ; i < deg ; i++ ) {
		pil p = dfs(adj[u][i],0);
		sum += p.se;
		mn = min(mn,p.fi);
	}
	pil ans = pil(max(mn,mx),sum);
	if(mx > mn)
		ans.se += mx-mn;
	return ans;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		for( int i = 1 ; i <= n ; i++ ) {
			scanf("%d",&dad[i]);
			adj[dad[i]].pb(i);
		}
		printf("Case #%d: %lld\n",tc,dfs(0,0).se);
	}
	return 0;
}
