#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;

const int MOD = (int) 1e9 + 7;

int n;
int dp[maxn];

int main() {
	scanf("%d",&n);
	dp[0] = 1;
	for( int i = 1 ; i <= n ; i++ ) {
		int mx = min(i,6);
		for( int j = 1 ; j <= mx ; j++ )
			dp[i] = (dp[i] + dp[i-j]) % MOD;
	}
	printf("%d\n",dp[n]);
	return 0;
}