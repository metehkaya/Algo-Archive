#include <bits/stdc++.h>
#define maxs 1000001
#define mod 1000000007
using namespace std;

int n;
int dp[maxs];
int sum[maxs];

int main() {
	dp[0] = sum[0] = 1;
	for( int i = 1 ; i < maxs ; i++ ) {
		for( int j = 1 ; (1<<j)-1 <= i ; j++ )
			dp[i] = ( dp[i] + dp[i-(1<<j)+1] ) % mod;
		sum[i] = ( sum[i-1] + dp[i] ) % mod;
	}
	scanf("%d",&n);
	for( int i = 1 , x,y ; i <= n ; i++ ) {
		scanf("%d%d",&x,&y);
		int ans = ( 2 * sum[y] - 1 ) % mod;
		if(x>0) {
			ans = (sum[y] - sum[x-1] + mod) % mod;
			ans = ( ans * 2 ) % mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
