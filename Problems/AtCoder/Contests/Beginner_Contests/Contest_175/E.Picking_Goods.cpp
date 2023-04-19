#include <bits/stdc++.h>
#define maxn 3001
using namespace std;
typedef long long LL;

int n,m,k;
int ar[maxn][maxn];
LL dp[maxn][maxn][4];

LL f(int r , int c , int d) {
	if(dp[r][c][d] != -1)
		return dp[r][c][d];
	dp[r][c][d] = 0;
	if(r < n) {
		dp[r][c][d] = max( dp[r][c][d] , f(r+1,c,0) );
		dp[r][c][d] = max( dp[r][c][d] , f(r+1,c,1) + ar[r+1][c] );
	}
	if(c < m) {
		dp[r][c][d] = max( dp[r][c][d] , f(r,c+1,d) );
		if(d < 3)
			dp[r][c][d] = max( dp[r][c][d] , f(r,c+1,d+1) + ar[r][c+1] );
	}
	return dp[r][c][d];
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 0 , x,y,z ; i < k ; i++ ) {
		scanf("%d%d%d",&x,&y,&z);
		ar[x][y] = z;
	}
	memset(dp,-1,sizeof(dp));
	LL ans = max( f(1,1,0) , f(1,1,1) + ar[1][1] );
	printf("%lld\n",ans);
	return 0;
}
