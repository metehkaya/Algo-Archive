#include <bits/stdc++.h>
#define maxn 1000
#define maxs 20001
using namespace std;
typedef long long LL;

struct data {
	int w,s,v;
}ar[maxn];

int n;
LL ans;
LL dp[maxs];

bool comp(const data& a, const data& b) {
	if(a.s + a.w == b.s + b.w)
		return a.w > b.w;
	return a.s + a.w < b.s + b.w;
}

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d%d%d",&ar[i].w,&ar[i].s,&ar[i].v);
	sort( ar , ar+n , comp );
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for( int i = 0 ; i < n ; i++ ) {
		for( int j = ar[i].s ; j >= 0 ; j-- )
			if( dp[j] != -1 && j + ar[i].w < maxs )
				dp[j+ar[i].w] = max( dp[j+ar[i].w] , dp[j] + ar[i].v );
	}
	for( int i = 0 ; i < maxs ; i++ )
		ans = max( ans , dp[i] );
	printf("%lld\n",ans);
	return 0;
}
