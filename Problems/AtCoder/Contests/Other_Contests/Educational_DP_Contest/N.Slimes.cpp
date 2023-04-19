#include <bits/stdc++.h>
#define maxn 401
using namespace std;
typedef long long LL;

int n;
LL sum[maxn];
int ar[maxn];
LL dp[maxn][maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		sum[i] = sum[i-1] + ar[i];
	}
	for( int len = 2 ; len <= n ; len++ )
		for( int i = 1 ; i <= n-len+1 ; i++ ) {
			int j = i+len-1;
			dp[i][j] = (1LL << 60);
			for( int k = i ; k < j ; k++ )
				dp[i][j] = min( dp[i][j] , dp[i][k] + dp[k+1][j] );
			dp[i][j] += sum[j] - sum[i-1];
		}
	printf("%lld\n",dp[1][n]);
	return 0;
}
