#include <bits/stdc++.h>
#define maxn 17
#define maxN (1<<17)
using namespace std;

const int INF = (1<<29);

int n,N;
int x[maxn];
int y[maxn];
int z[maxn];
int d[maxn][maxn];
int dp[maxN][maxn];

int getCost(int i , int j) {
	return abs(x[i]-x[j]) + abs(y[i]-y[j]) + max(z[j]-z[i],0);
}

int main() {
	scanf("%d",&n);
	N = (1<<n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	for( int i = 0 ; i < n ; i++ )
		for( int j = i+1 ; j < n ; j++ ) {
			d[i][j] = getCost(i,j);
			d[j][i] = getCost(j,i);
		}
	for( int k = 0 ; k < n ; k++ )
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < n ; j++ )
				d[i][j] = min( d[i][j] , d[i][k] + d[k][j] );
	for( int i = 0 ; i < N ; i++ )
		for( int j = 0 ; j < n ; j++ )
			dp[i][j] = INF;
	dp[1][0] = 0;
	for( int bmask = 1 ; bmask < N ; bmask++ )
		for( int i = 0 ; i < n ; i++ )
			if(dp[bmask][i] != INF)
				for( int j = 0 ; j < n ; j++ )
					if((bmask & (1<<j)) == 0) {
						int bmask2 = (bmask | (1<<j));
						dp[bmask2][j] = min(dp[bmask2][j],dp[bmask][i]+getCost(i,j));
					}
	int ans = INF;
	for( int i = 1 ; i < n ; i++ )
		if(dp[N-1][i] != INF)
			ans = min(ans,dp[N-1][i]+d[i][0]);
	printf("%d\n",ans);
	return 0;
}
