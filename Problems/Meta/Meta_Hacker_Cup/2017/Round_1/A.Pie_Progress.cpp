#include <bits/stdc++.h>
#define maxn 301
using namespace std;
typedef long long LL;

int T,n,m;
LL dp[maxn][maxn];
LL sum[maxn][maxn];
int ar[maxn][maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	memset(dp,-1,sizeof(dp));
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&m);
		for( int i = 1 ; i <= n ; i++ ) {
			for( int j = 1 ; j <= m ; j++ )
				scanf("%d",&ar[i][j]);
			sort(ar[i]+1,ar[i]+m+1);
			for( int j = 1 ; j <= m ; j++ )
				sum[i][j] = sum[i][j-1] + ar[i][j];
		}
		dp[0][0] = 0;
		for( int i = 1 ; i <= n ; i++ )
			for( int j = i ; j <= n ; j++ ) {
				int mx = min(j,m);
				for( int k = 0 ; k <= mx ; k++ )
					if(dp[i-1][j-k] != -1) {
						int val = dp[i-1][j-k] + sum[i][k] + k*k;
						if(dp[i][j] == -1 || val < dp[i][j])
							dp[i][j] = val;
					}
			}
		printf("Case #%d: %lld\n",tc,dp[n][n]);
	}
	return 0;
}

