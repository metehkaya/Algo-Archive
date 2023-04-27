#include <bits/stdc++.h>
#define maxn 51
using namespace std;
typedef long long LL;

int n,m;
int ar[maxn][maxn];
int sum[maxn][maxn];
LL dp[maxn][maxn][maxn][maxn];

int query(int r1 , int c1 , int r2 , int c2) {
	return sum[r2][c2] + sum[r1-1][c1-1] - sum[r2][c1-1] - sum[r1-1][c2];
}

LL f(int r1 , int c1 , int r2 , int c2) {
	if(r1 == r2 && c1 == c2)
		return 0;
	if(dp[r1][c1][r2][c2] != -1)
		return dp[r1][c1][r2][c2];
	dp[r1][c1][r2][c2] = LLONG_MAX;
	int add = query(r1,c1,r2,c2);
	for( int c = c1 ; c < c2 ; c++ ) {
		LL cost = f(r1,c1,r2,c) + f(r1,c+1,r2,c2) + add;
		dp[r1][c1][r2][c2] = min(dp[r1][c1][r2][c2],cost);
	}
	for( int r = r1 ; r < r2 ; r++ ) {
		LL cost = f(r1,c1,r,c2) + f(r+1,c1,r2,c2) + add;
		dp[r1][c1][r2][c2] = min(dp[r1][c1][r2][c2],cost);
	}
	return dp[r1][c1][r2][c2];
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ) {
			scanf("%d",&ar[i][j]);
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + ar[i][j];
		}
	memset(dp,-1,sizeof(dp));
	printf("%lld\n",f(1,1,n,m));
	return 0;
}
