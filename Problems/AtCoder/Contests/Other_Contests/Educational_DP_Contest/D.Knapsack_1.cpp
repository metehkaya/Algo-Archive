#include <bits/stdc++.h>
#define maxn 100
#define maxm 100001
using namespace std;
typedef long long LL;

LL ans;
int n,m;
int w[maxn];
int v[maxn];
LL dp[maxm];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d%d",&w[i],&v[i]);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for( int i = 0 ; i < n ; i++ )
		for( int j = m - w[i] ; j >= 0 ; j-- )
			if( dp[j] != -1 )
				dp[j+w[i]] = max( dp[j+w[i]] , dp[j]+v[i] );
	for( int i = 0 ; i <= m ; i++ )
		ans = max( ans , dp[i] );
	printf("%lld\n",ans);
	return 0;
}
