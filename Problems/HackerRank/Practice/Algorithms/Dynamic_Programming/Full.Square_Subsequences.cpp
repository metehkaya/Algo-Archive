#include <bits/stdc++.h>
#define maxn 201
#define mod 1000000007
using namespace std;

int T,n,ans;
char str[maxn];
int dp[maxn][maxn][maxn];

int f( int k , int i , int j ) {
	if( i == k || j == n )
		return dp[k][i][j] = 0;
	if( dp[k][i][j] != -1 )
		return dp[k][i][j];
	dp[k][i][j] = 0;
	if( str[i] == str[j] )
		dp[k][i][j] = ( f(k,i+1,j+1) + 1 ) % mod;
	dp[k][i][j] = ( dp[k][i][j] + f(k,i+1,j) ) % mod;
	dp[k][i][j] = ( dp[k][i][j] + f(k,i,j+1) ) % mod;
	dp[k][i][j] = ( dp[k][i][j] - f(k,i+1,j+1) + mod ) % mod;
	return dp[k][i][j];
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%s",str);
		n = strlen(str);
		ans = 0;
		memset(dp, -1, sizeof(dp));
		for( int k = 1 ; k < n ; k++ )
			for( int i = 0 ; i < k ; i++ )
				if( str[i] == str[k] )
					ans = ( ans + f(k,i+1,k+1) + 1 ) % mod;
		printf("%d\n",ans);
	}
	return 0;
}
