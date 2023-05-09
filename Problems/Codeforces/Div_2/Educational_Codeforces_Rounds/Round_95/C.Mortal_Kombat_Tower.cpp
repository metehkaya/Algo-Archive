#include <bits/stdc++.h>
#define maxn 200003
using namespace std;

int T,n;
int ar[maxn];
int dp[maxn][2];

void reset() {
	for( int i = 0 ; i <= n+1 ; i++ )
		dp[i][0] = dp[i][1] = -1;
}

void input() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
}

int f(int x , int k) {
	if(x == n+1)
		return 0;
	if(dp[x][k] != -1)
		return dp[x][k];
	dp[x][k] = INT_MAX;
	if(k == 0) {
		dp[x][k] = min( f(x+1,!k) , dp[x][k] );
		if(x < n)
			dp[x][k] = min( f(x+2,!k) , dp[x][k] );
	}
	else {
		int add = ar[x];
		dp[x][k] = min( f(x+1,!k) + add , dp[x][k] );
		if(x < n) {
			add += ar[x+1];
			dp[x][k] = min( f(x+2,!k) + add , dp[x][k] );
		}
	}
	return dp[x][k];
}

void solve() {
	printf("%d\n",f(1,1));
}

int main() {
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
	}
	return 0;
}
