#include <bits/stdc++.h>
#define maxn 2001
#define mod 1000000007LL
using namespace std;
typedef long long LL;

int n,k;
LL ans = 0;
LL dp[maxn][maxn];

int main() {
	scanf("%d%d",&n,&k);
	dp[0][1] = 1;
	for( int i = 1 ; i <= k ; i++ ) {
		for( int j = 0 ; j <= n ; j++ ) {
			dp[i][j] = dp[i-1][j] * j + dp[i-1][j] * (n-j) * (n-1);
			dp[i][j] %= mod;
			if(j > 0)
				dp[i][j] += dp[i-1][j-1] * (n-j+1);
			if(j < n)
				dp[i][j] += dp[i-1][j+1] * (j+1) * (n-1);
			dp[i][j] %= mod;
		}
	}
	for( int i = 1 ; i <= n ; i++ )
		ans = (ans + dp[k][i]) % mod;
	ans = (ans*n) % mod;
	printf("%lld\n",ans);
	return 0;
}
