#include <bits/stdc++.h>
#define maxn 21
#define maxbm (1<<maxn)
#define mod 1000000007
using namespace std;

int n;
bool ar[maxn][maxn];
int dp[maxn][maxbm];

int f(int curr, int bmask) {
	if(curr == n)
		return 1;
	if(dp[curr][bmask] != -1)
		return dp[curr][bmask];
	dp[curr][bmask] = 0;
	for( int i = 0 ; i < n ; i++ )
		if( ar[curr][i] && (bmask & (1<<i)) == 0 )
			dp[curr][bmask] = ( dp[curr][bmask] + f( curr+1 , (bmask | (1<<i)) ) ) % mod;
	return dp[curr][bmask];
}

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < n ; j++ )
			cin >> ar[i][j];
	memset(dp, -1, sizeof(dp));
	printf("%d\n",f(0,0));
	return 0;
}
