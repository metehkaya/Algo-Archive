#include <bits/stdc++.h>
#define maxn 5003
using namespace std;

int n,m;
char s[maxn];
char t[maxn];
int dp[maxn][maxn];

int f(int i, int j) {
	if(i == n || j == m)
		return 0;
	if( dp[i][j] != -1 )
		return dp[i][j];
	dp[i][j] = max(f(i,j+1), f(i+1,j));
	if(s[i] == t[j])
		dp[i][j] = max(dp[i][j], f(i+1,j+1)+1);
	return dp[i][j];
}

int main() {
	scanf("%s%s",s,t);
	n = strlen(s);
	m = strlen(t);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",f(0,0));
	return 0;
}
