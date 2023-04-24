#include <bits/stdc++.h>
#define maxn 10001
using namespace std;

int T,n;
int ar[maxn];
int dp[maxn][4];

int f(int i , int x) {
	if(i == n)
		return 0;
	if(dp[i][x] != -1)
		return dp[i][x];
	dp[i][x] = INT_MAX;
	for( int j = 0 ; j < 4 ; j++ ) {
		int cost = 0;
		if(ar[i+1] == ar[i] && j != x)
			cost = 1;
		if(ar[i+1] > ar[i] && j <= x)
			cost = 1;
		if(ar[i+1] < ar[i] && x <= j)
			cost = 1;
		dp[i][x] = min( dp[i][x] , f(i+1,j) + cost );
	}
	return dp[i][x];
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		int ans = INT_MAX;
		memset(dp,-1,sizeof(dp));	
		for( int i = 0 ; i < 4 ; i++ )
			ans = min(ans,f(1,i));
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
