#include <bits/stdc++.h>
#define maxn 52
#define maxk 1001
using namespace std;

int n,m,k;
string ways = "RLDU";
char str[maxn][maxn];
int dp[maxn][maxn][maxk];
int dir[4][2] = {{0,+1},{0,-1},{+1,0},{-1,0}};

int f(int r, int c, int d) {
	if(str[r][c] == '*')
		return 0;
	if(d == 0)
		return INT_MAX;
	if(dp[r][c][d] != -1)
		return dp[r][c][d];
	dp[r][c][d] = INT_MAX;
	for( int i = 0 ; i < 4 ; i++ ) {
		int x = r + dir[i][0];
		int y = c + dir[i][1];
		int add = ways[i] != str[r][c];
		if(x < 0 || x >= n || y < 0 || y >= m)
			continue;
		int tmp = f(x,y,d-1);
		if(tmp != INT_MAX)
			dp[r][c][d] = min(dp[r][c][d], tmp + add);
	}
	return dp[r][c][d];
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 0 ; i < n ; i++ )
		scanf("%s",str[i]);
	memset(dp, -1, sizeof(dp));
	int ans = f(0,0,k);
	if(ans == INT_MAX)
		puts("-1");
	else
		printf("%d\n",ans);
	return 0;
}
