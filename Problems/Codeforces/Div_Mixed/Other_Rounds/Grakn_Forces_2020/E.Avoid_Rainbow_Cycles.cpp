#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200003
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

LL ans;
int n,m,e;
int a[maxn];
int b[maxn];
int par[maxn];
int cnt[maxn];
vector<pii> edges;

int findPar(int u) {
	if(par[u] == -1)
		return u;
	return u = findPar(par[u]);
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&a[i]);
	for( int i = 1 ; i <= m ; i++ )
		scanf("%d",&b[i]);
	for( int i = 1 , deg ; i <= n ; i++ ) {
		scanf("%d",&deg);
		for( int j = 0 , x ; j < deg ; j++ ) {
			scanf("%d",&x);
			ans += a[i]+b[x];
			edges.pb( pii( a[i]+b[x] , pi(i,n+x) ) );
		}
	}
	for( int i = 1 ; i <= n+m ; i++ )
		cnt[i] = 1 , par[i] = -1;
	e = edges.size();
	sort(edges.begin(),edges.end());
	for( int i = e-1 ; i >= 0 ; i-- ) {
		int c = edges[i].fi;
		int u = edges[i].se.fi;
		int v = edges[i].se.se;
		u = findPar(u);
		v = findPar(v);
		if(u == v)
			continue;
		ans -= c;
		if(cnt[u] < cnt[v]) {
			cnt[v] += cnt[u];
			par[u] = v;
		}
		else {
			cnt[u] += cnt[v];
			par[v] = u;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
