#include <bits/stdc++.h>
#define maxs 217287
using namespace std;

int T,n;
int dp[41];
int sum[maxs];
bool notPrime[maxs];

int main() {
	dp[0] = dp[1] = dp[2] = dp[3] = 1;
	for( int i = 4 ; i <= 40 ; i++ )
		dp[i] = dp[i-1] + dp[i-4];
	notPrime[0] = notPrime[1] = true;
	for( int i = 2 ; i < maxs ; i++ )
		if(!notPrime[i])
			if( i <= maxs/i )
				for( int j = i*i ; j < maxs ; j += i )
					notPrime[j] = true;
	for( int i = 1 ; i < maxs ; i++ )
		sum[i] = sum[i-1] + !notPrime[i];
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		printf("%d\n",sum[dp[n]]);
	}
	return 0;
}
