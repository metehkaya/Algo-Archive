#include <bits/stdc++.h>
#define maxn 203
using namespace std;

int n,m;
int ar[maxn][maxn];
int dp[maxn][maxn];

bool check( int energy ) {
	
	memset( dp , -1 , sizeof( dp ) );
	dp[1][1] = energy;
	
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ) {
			
			if( i == 1 && j == 1 )
				continue;
			
			if( i > 1 && dp[i-1][j] != -1 && dp[i-1][j] + ar[i][j] > 0 )
				dp[i][j] = dp[i-1][j] + ar[i][j];
			
			if( j > 1 && dp[i][j-1] != -1 && dp[i][j-1] + ar[i][j] > 0 )
				dp[i][j] = max( dp[i][j] , dp[i][j-1] + ar[i][j] );
			
		}
	
	if( dp[n][m] == -1 )
		return false;
	
	return true;
	
}

int main() {
	
	scanf( "%d%d" , &n , &m );
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ )
			scanf( "%d" , &ar[i][j] );
	
	int l = 1 , r = 400000 , ans = -1;
	while( l <= r ) {
		int mid = (l + r) >> 1;
		if( check(mid) )
			ans = mid , r = mid - 1;
		else
			l = mid + 1;
	}
	
	printf( "%d\n" , ans );
	
	return 0;

}
