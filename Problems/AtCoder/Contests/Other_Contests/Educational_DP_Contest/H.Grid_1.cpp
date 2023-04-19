#include <bits/stdc++.h>
#define maxn 1003
#define mod 1000000007
using namespace std;

int n,m;
char s[maxn][maxn];
int dp[maxn][maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%s",s[i]+1);
	dp[1][1] = 1;
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ )
			if( s[i][j] == '.' && (i > 1 || j > 1) )
				dp[i][j] = ( dp[i-1][j] + dp[i][j-1] ) % mod;
	printf("%d\n",dp[n][m]);
	return 0;
}
