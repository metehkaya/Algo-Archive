#include <bits/stdc++.h>
using namespace std;

const int K = 30;
const int N = 50;

int T,n,k,p;
int a[N][K];
int dp[N][N*K+1];

int f(int curr, int rem) {
	if(curr == n)
		return (rem == 0 ? 0 : -1);
	if(dp[curr][rem] != -1)
		return dp[curr][rem];
	dp[curr][rem] = -2;
	int val = f(curr+1, rem);
	if(val >= 0)
		dp[curr][rem] = val;
	int sum = 0;
	for( int i = 0 ; i < min(rem, k) ; i++ ) {
		sum += a[curr][i];
		val = f( curr+1 , rem-i-1 );
		if(val >= 0)
			dp[curr][rem] = max( dp[curr][rem] , sum + val );
	}
	return dp[curr][rem];
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d",&n,&k,&p);
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < k ; j++ )
				scanf("%d",&a[i][j]);
		memset(dp, -1, sizeof(dp));
		printf("Case #%d: %d\n", tc, f(0,p));
	}
	return 0;
}
