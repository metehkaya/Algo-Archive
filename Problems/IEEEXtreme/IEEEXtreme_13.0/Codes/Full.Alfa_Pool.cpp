#include <bits/stdc++.h>
#define maxs 100001
#define mod 1000000007
using namespace std;

int n;
int dp[maxs];

int main() {
	dp[0] = 1;
	for( int i = 1 ; i < maxs ; i++ )
		for( int j = 1 ; (1<<j)-1 <= i ; j++ )
			dp[i] = ( dp[i] + dp[i-(1<<j)+1] ) % mod;
	scanf("%d",&n);
	for( int i = 1 , x ; i <= n ; i++ ) {
		scanf("%d",&x);
		int ans = 1;
		if(x)
			ans = (2*dp[x])%mod;
		printf("%d\n",ans);
	}
	return 0;
}
