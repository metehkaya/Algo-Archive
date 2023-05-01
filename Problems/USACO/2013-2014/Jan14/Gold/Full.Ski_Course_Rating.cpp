#include <bits/stdc++.h>
#define maxn 500
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

LL ans;
int n,m,t,e;
int sz[maxn*maxn];
int lvl[maxn*maxn];
int cnt[maxn*maxn];
int dad[maxn*maxn];
int ar[maxn][maxn];
vector<pii> edges;

int findPar(int u) {
	if(u == dad[u])
		return u;
	return dad[u] = findPar(dad[u]);
}

void merge(int c , int u , int v) {
	bool incLevel = (lvl[u] == lvl[v]);
	int smaller = (lvl[u] < lvl[v]) ? u : v;
	int bigger = (smaller == u) ? v : u;
	lvl[bigger] += incLevel;
	sz[bigger] += sz[smaller];
	cnt[bigger] += cnt[smaller];
	dad[smaller] = bigger;
	if(sz[bigger] >= t) {
		ans += (LL) cnt[bigger] * c;
		cnt[bigger] = 0;
	}
}

void input() {
	scanf("%d%d%d",&n,&m,&t);
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			scanf("%d",&ar[i][j]);
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			scanf("%d",&cnt[i*m+j]);
}

void solve() {
	if(t == 1) {
		ans = 0;
		return;
	}
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m-1 ; j++ )
			edges.pb( pii( abs(ar[i][j]-ar[i][j+1]) , pi(i*m+j,i*m+j+1) ) );
	for( int i = 0 ; i < n-1 ; i++ )
		for( int j = 0 ; j < m ; j++ )
			edges.pb( pii( abs(ar[i][j]-ar[i+1][j]) , pi(i*m+j,i*m+j+m) ) );
	for( int i = 0 ; i < n*m ; i++ )
		dad[i] = i , sz[i] = 1;
	e = edges.size();
	sort(edges.begin(),edges.end());
	for( int id = 0 ; id < e ; id++ ) {
		int c = edges[id].fi;
		int u = edges[id].se.fi;
		int v = edges[id].se.se;
		u = findPar(u);
		v = findPar(v);
		if(u != v)
			merge(c,u,v);
	}
}

void output() {
	printf("%lld\n",ans);
}

void io() {
	freopen("skilevel.in","r",stdin);
	freopen("skilevel.out","w",stdout);
}

int main() {
	io();
	input();
	solve();
	output();
	return 0;
}
