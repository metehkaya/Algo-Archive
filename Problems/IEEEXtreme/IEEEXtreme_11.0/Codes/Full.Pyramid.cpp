#include <bits/stdc++.h>
#define fi first
#define se second
#define maxk 17
#define maxn 100003
#define mod 1000000007
using namespace std;
typedef pair<int,int> pi;

int s;
int comb[maxk][maxk];

pi dp[maxn][maxk];

int f( int ind , int step , int rem ) {
	if( ind == step )
		return 1;
	if( dp[rem][ind].se == step + 1 )
		return dp[rem][ind].fi;
	dp[rem][ind] = pi( 0 , step + 1 );
	dp[rem][ind].fi = ( dp[rem][ind].fi + f( ind + 1 , step , rem ) ) % mod;
	if( comb[step][ind] <= rem )
		dp[rem][ind].fi = ( dp[rem][ind].fi + f( ind , step , rem - comb[step][ind] ) ) % mod;
	return dp[rem][ind].fi;
}

int main() {
	
	for( int i = 0 ; i < maxk ; i++ )
		comb[i][0] = 1;
	
	for( int i = 1 ; i < maxk ; i++ )
		for( int j = 1 ; j <= i ; j++ )
			comb[i][j] = ( comb[i-1][j-1] + comb[i-1][j] ) % mod;
	
	scanf( "%d" , &s );
	
	int ans = 0;
	for( int i = 0 ; (1<<i) <= s ; i++ )
		ans = ( ans + f( 0 , i , s - (1 << i) ) ) % mod;
	
	printf( "%d\n" , ans );
	
	return 0;

}
