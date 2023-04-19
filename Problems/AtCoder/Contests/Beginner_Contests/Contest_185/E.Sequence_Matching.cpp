#include <bits/stdc++.h>
#define maxn 1003
using namespace std;

int n,m;
int a[maxn];
int b[maxn];
int dp[maxn][maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&a[i]);
	for( int j = 1 ; j <= m ; j++ )
		scanf("%d",&b[j]);
	for( int i = 0 ; i <= n ; i++ )
		for( int j = 0 ; j <= m ; j++ )
			if(i+j) {
				dp[i][j] = INT_MAX;
				if(i)
					dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
				if(j)
					dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
				if(i && j)
					dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(a[i]!=b[j]));
			}
	printf("%d\n",dp[n][m]);
	return 0;
}
