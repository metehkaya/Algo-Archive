#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int n,ans;
int ar[maxn][3];
int dp[maxn][3];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < 3 ; j++ )
			scanf("%d",&ar[i][j]);
	for( int i = 0 ; i < 3 ; i++ )
		dp[0][i] = ar[0][i];
	for( int i = 1 ; i < n ; i++ )
		for( int j = 0 ; j < 3 ; j++ )
			for( int k = 0 ; k < 3 ; k++ )
				if( j != k )
					dp[i][j] = max( dp[i][j] , dp[i-1][k] + ar[i][j] );
	for( int i = 0 ; i < 3 ; i++ )
		ans = max( ans , dp[n-1][i] );
	printf("%d\n",ans);
	return 0;
}
