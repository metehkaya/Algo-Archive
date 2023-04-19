#include <bits/stdc++.h>
#define maxn 2001
#define mod 1000000007
using namespace std;

int n;
int dp[maxn];
int sum[maxn];

int main() {
	scanf("%d",&n);
	dp[0] = 1;
	sum[0] = sum[1] = sum[2] = 1;
	for( int i = 3 ; i <= n ; i++ ) {
		dp[i] = sum[i-3];
		sum[i] = (sum[i-1] + dp[i]) % mod;
	}
	printf("%d\n",dp[n]);
	return 0;
}
