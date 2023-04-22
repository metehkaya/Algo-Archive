#include <bits/stdc++.h>
#define maxm 1003
#define mod 1000000007
using namespace std;

int T,m;
int dp[3][maxm];
char str[3][maxm];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	memset(dp,-1,sizeof(dp));
}

void read() {
	scanf("%d",&m);
	for( int i = 0 ; i < 3 ; i++ )
		scanf("%s",str[i]+1);
	str[0][m+1] = str[1][m+1] = str[2][m+1] = '.';
}

int solve(int r , int c) {
	if(c == m + 1) {
		if( r == 2 )
			return 1;
		return 0;
	}
	if(dp[r][c] != -1)
		return dp[r][c];
	dp[r][c] = 0;
	if(r == 0 && str[1][c] == '.' && str[1][c+1] == '.')
		dp[r][c] = solve(1,c+1);
	if(r == 2 && str[1][c] == '.' && str[1][c+1] == '.')
		dp[r][c] = solve(1,c+1);
	if(r == 1) {
		if(str[0][c] == '.' && str[0][c+1] == '.')
			dp[r][c] = solve(0,c+1);
		if(str[2][c] == '.' && str[2][c+1] == '.')
			dp[r][c] += solve(2,c+1);
		dp[r][c] %= mod;
	}
	return dp[r][c];
}

void print(int tc) {
	if(str[0][1] == '#')
		printf("Case #%d: 0\n",tc);
	else
		printf("Case #%d: %d\n",tc,solve(0,1));
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		read();
		print(tc);
	}
	return 0;
}

