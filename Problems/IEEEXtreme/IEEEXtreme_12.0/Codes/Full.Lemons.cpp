#include <bits/stdc++.h>
#define maxn 10002
using namespace std;

int n,a,b;
int K = 103;
int dp[maxn][2];

int f( int len , int pl ) {
	if( dp[len][pl] != -1 )
		return dp[len][pl];
	dp[len][pl] = INT_MAX;
	int ind = 1 + pl * (len - 1);
	for( int i = max( 2 , len / 2 - K ) ; i <= min( len , len / 2 + K ) ; i++ ) {
		int cost = a * abs( ind - i ) + b;
		int left , right;
		if( i == 2 )
			left = 0;
		else
			left = a + f( i - 1 , 1 );
		if( i == len )
			right = 0;
		else
			right = f( len - i + 1 , 0 );
		dp[len][pl] = min( dp[len][pl] , cost + max( left , right ) );
	}
	return dp[len][pl];
}

int main() {
	scanf( "%d%d%d" , &n , &a , &b );
	memset( dp , -1 , sizeof(dp) );
	if( n == 2 )
		puts( "0" );
	else
		printf( "%d\n" , f( n - 1 , 0 ) + a );
	return 0;
}