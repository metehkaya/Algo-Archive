#include <bits/stdc++.h>
#define maxn 3001
using namespace std;

int T,n,k;
double p;
double dp2[maxn];
double prob[maxn];
double dp[maxn][maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%lf",&n,&k,&p);
		dp[0][0] = 1;
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 0 ; j <= i ; j++ ) {
				dp[i][j] = 0;
				if(j)
					dp[i][j] += dp[i-1][j-1] * p;
				if(j<i)
					dp[i][j] += dp[i-1][j] * (1-p);
			}
		for( int i = 1 ; i <= n ; i++ ) {
			prob[i] = 0;
			for( int j = k ; j <= i ; j++ )
				prob[i] += dp[i][j];
		}
		for( int i = 1 ; i <= n ; i++ ) {
			dp2[i] = 0;
			for( int j = k ; j <= i ; j++ )
				dp2[i] = max( dp2[i] , dp2[i-j] + prob[j] );
		}
		printf("Case #%d: %lf\n",tc,dp2[n]);
	}
	return 0;
}
