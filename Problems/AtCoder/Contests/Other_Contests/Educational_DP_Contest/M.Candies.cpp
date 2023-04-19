#include <bits/stdc++.h>
#define maxn 101
#define maxk 100001
#define mod 1000000007
using namespace std;

int n,k;
int ar[maxn];
int dp[maxn][maxk];
int sum[maxn][maxk];

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	dp[0][0] = 1;
	for( int i = 0 ; i <= k ; i++ )
		sum[0][i] = 1;
	for( int i = 1 ; i <= n ; i++ ) {
		for( int j = 0 ; j <= k ; j++ ) {
			int l = max(j-ar[i], 0);
			dp[i][j] = sum[i-1][j];
			if(l > 0)
				dp[i][j] = ( dp[i][j] + mod - sum[i-1][l-1] ) % mod;
		}
		sum[i][0] = dp[i][0];
		for( int j = 1 ; j <= k ; j++ )
			sum[i][j] = ( sum[i][j-1] + dp[i][j] ) % mod;
	}
	printf("%d\n",dp[n][k]);
	return 0;
}
