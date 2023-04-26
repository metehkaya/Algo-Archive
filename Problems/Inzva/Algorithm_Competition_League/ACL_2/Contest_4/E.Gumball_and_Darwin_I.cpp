#include <bits/stdc++.h>
#define maxn 1501
using namespace std;

int n,ans;
int chain[maxn];
int ar[maxn][maxn];
int dp[maxn][maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= n ; j++ )
			scanf("%d",&ar[i][j]);
	if(n == 2) {
		printf("%d\n",ar[1][2]);
		return 0;
	}
	dp[2][1] = ar[1][2];
	for( int i = 3 ; i <= n ; i++ ) {
		for( int j = 1 ; j < i-1 ; j++ )
			dp[i][j] = ar[i][i-1] + dp[i-1][j];
		dp[i][i-1] = INT_MAX;
		for( int j = 1 ; j < i-1 ; j++ )
			dp[i][i-1] = min( dp[i][i-1] , dp[i-1][j] + ar[i][j] );
	}
	for( int i = n-1 ; i >= 1 ; i-- )
		chain[i] = ar[i][i+1] + chain[i+1];
	ans = INT_MAX;
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= i ; j++ )
			if(i == 1 || j < i) {
				int cost = dp[i][j];
				if(i < n)
					cost += ar[j][i+1] + chain[i+1];
				ans = min(ans,cost);
			}
	printf("%d\n",ans);
	return 0;
}
