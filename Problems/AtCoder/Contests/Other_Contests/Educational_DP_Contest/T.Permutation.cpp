#include <bits/stdc++.h>
#define maxn 3002
#define mod 1000000007
using namespace std;
typedef long long LL;

int n;
char s[maxn];
int sum[maxn];
int dp[maxn][maxn];

int main() {
	scanf("%d%s",&n,s+1);
	dp[1][1] = sum[1] = 1;
	for( int i = 2 ; i <= n ; i++ ) {
		if(s[i-1] == '<')
			for( int j = 2 ; j <= i ; j++ )
				dp[i][j] = sum[j-1];
		else
			for( int j = 1 ; j < i ; j++ )
				dp[i][j] = (sum[i-1] - sum[j-1] + mod) % mod;
		for( int j = 1 ; j <= n ; j++ )
			sum[j] = ( sum[j-1] + dp[i][j] ) % mod;
	}
	printf("%d\n",sum[n]);
	return 0;
}
