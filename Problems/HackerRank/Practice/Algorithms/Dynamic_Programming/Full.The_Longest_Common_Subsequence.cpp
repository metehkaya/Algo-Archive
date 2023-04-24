#include <bits/stdc++.h>
#define maxn 100
using namespace std;

int n,m;
int a[maxn];
int b[maxn];
int dp[maxn][maxn];
int way[maxn][maxn];

int f(int i, int j) {
	if(i == n || j == m)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int tmp = f(i,j+1);
	if(tmp > dp[i][j]) {
		dp[i][j] = tmp;
		way[i][j] = 1;
	}
	tmp = f(i+1,j);
	if(tmp > dp[i][j]) {
		dp[i][j] = tmp;
		way[i][j] = 2;
	}
	if(a[i] == b[j]) {
		tmp = f(i+1,j+1) + 1;
		if(tmp > dp[i][j]) {
			dp[i][j] = tmp;
			way[i][j] = 3;
		}
	}
	return dp[i][j];
}

void output(int i, int j) {
	if(i == n || j == m)
		return;
	if(way[i][j] == 1)
		output(i,j+1);
	else if(way[i][j] == 2)
		output(i+1,j);
	else {
		printf("%d ", a[i]);
		output(i+1,j+1);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&a[i]);
	for( int i = 0 ; i < m ; i++ )
		scanf("%d",&b[i]);
	memset(dp, -1, sizeof(dp));
	f(0,0);
	output(0,0);
	return 0;
}
