#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200003
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<LL,int> pLi;

int n;
LL ans;
LL ar[maxn];
vector<int> adj[maxn];

pLi dfs(int u) {
	if(adj[u].empty()) {
		ans = max(ans,ar[u]);
		return pLi(ar[u],1);
	}
	int leaf = 0;
	LL total = ar[u];
	for( int i = 0 ; i < adj[u].size() ; i++ ) {
		pLi temp = dfs(adj[u][i]);
		total += temp.fi;
		leaf += temp.se;
	}
	LL res = total/leaf + !(!(total%leaf));
	ans = max(ans,res);
	return pLi(total,leaf);
}

int main() {
	scanf("%d",&n);
	for( int i = 2 , u ; i <= n ; i++ ) {
		scanf("%d",&u);
		adj[u].pb(i);
	}
	for( int i = 1 ; i <= n ; i++ )
		scanf("%lld",&ar[i]);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
