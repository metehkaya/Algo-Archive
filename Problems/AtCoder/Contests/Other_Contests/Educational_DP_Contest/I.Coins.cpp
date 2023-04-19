#include <bits/stdc++.h>
#define maxn 3000
using namespace std;

int n;
double p[maxn];
double dp[maxn][maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%lf",&p[i]);
	dp[0][0] = 1;
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 0 ; j <= i ; j++ ) {
			if(j)
				dp[i][j] = dp[i-1][j-1] * p[i];
			dp[i][j] += dp[i-1][j] * (1-p[i]);
		}
	double ans = 0;
	for( int i = n/2+1 ; i <= n ; i++ )
		ans += dp[n][i];
	printf("%.10lf\n",ans);
	return 0;
}
