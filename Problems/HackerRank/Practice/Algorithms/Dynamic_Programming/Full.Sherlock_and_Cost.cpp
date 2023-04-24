#include <bits/stdc++.h>
#define maxv 101
#define maxn 100001
using namespace std;

int T,n;
int ar[maxn];
int p[maxn][maxv];
int m[maxn][maxv];
int dp[maxn][maxv];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		if(n == 1) {
			puts("0");
			continue;
		}
		for( int i = 1 ; i <= ar[1] ; i++ )
			p[1][i] = i , m[1][i] = -i;
		for( int i = 2 , val ; i <= n ; i++ ) {
			val = -2 * maxv;
			for( int j = 1 ; j <= ar[i] ; j++ ) {
				if(j <= ar[i-1])
					val = max( val , m[i-1][j] );
				dp[i][j] = val + j;
			}
			val = -2 * maxv;
			for( int j = ar[i-1] ; j > ar[i] ; j-- )
				val = max( val , p[i-1][j] );
			for( int j = min( ar[i] , ar[i-1] ) ; j >= 1 ; j-- ) {
				val = max( val , p[i-1][j] );
				dp[i][j] = max( dp[i][j] , val - j );
			}
			if(i == n)
				break;
			for( int j = 1 ; j <= ar[i] ; j++ )
				p[i][j] = dp[i][j] + j , m[i][j] = dp[i][j] - j;
		}
		int res = dp[n][1];
		for( int i = 2 ; i <= ar[n] ; i++ )
			res = max( res , dp[n][i] );
		printf("%d\n",res);
	}
	return 0;
}
