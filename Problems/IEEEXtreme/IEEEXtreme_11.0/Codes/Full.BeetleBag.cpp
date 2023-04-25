#include <bits/stdc++.h>
#define maxn 201
#define maxc 501
using namespace std;

int T,n,c;
int w[maxn];
int f[maxn];
int dp[maxc];

void reset() {
	memset( dp , -1 , sizeof(dp) );
}

void read() {
	scanf( "%d%d" , &c , &n );
	for( int i = 0 ; i < n ; i++ )
		scanf( "%d%d" , &w[i] , &f[i] );
}

void solve() {
	dp[0] = 0;
	for( int i = 0 ; i < n ; i++ )
		for( int j = c - w[i] ; j >= 0 ; j-- )
		if( dp[j] != -1 )
				dp[j + w[i]] = max( dp[j + w[i]] , dp[j] + f[i] );
	int ans = 0;
	for( int i = 0 ; i <= c ; i++ )
		ans = max( ans , dp[i] );
	printf( "%d\n" , ans );
}

int main() {
	scanf( "%d" , &T );
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		read();
		solve();
	}
	return 0;
}
