#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100003
#define mod 1000000007
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

int n,ans;
int dad[maxn];
int cnt[maxn];
int lvl[maxn];
vector<pii> v;

int findRoot(int u) {
	if( !dad[u] )
		return u;
	return dad[u] = findRoot( dad[u] );
}

void merge(int u , int v , int val) {
	LL mult = (LL) cnt[u] * cnt[v];
	mult %= mod;
	mult *= (LL) val;
	mult %= mod;
	ans = ( ans + mult ) % mod;
	if( lvl[u] < lvl[v] ) {
		dad[u] = v;
		cnt[v] += cnt[u];
	}
	else {
		if( lvl[u] == lvl[v] )
			lvl[u]++;
		dad[v] = u;
		cnt[u] += cnt[v];
	}
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ,x,y,z ; i < n ; i++ ) {
		scanf("%d%d%d",&x,&y,&z);
		v.pb( pii( z , pi(x,y) ) );
	}
	sort( v.begin() , v.end() );
	for( int i = 1 ; i <= n ; i++ )
		cnt[i] = 1;
	for( int i = 0 ; i < n-1 ; i++ ) {
		int z = v[i].fi;
		int x = v[i].se.fi;
		int y = v[i].se.se;
		x = findRoot(x);
		y = findRoot(y);
		merge(x,y,z);
	}
	printf("%d\n",ans);
	return 0;
}
