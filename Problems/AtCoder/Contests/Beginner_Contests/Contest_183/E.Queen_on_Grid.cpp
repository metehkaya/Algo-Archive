#include <bits/stdc++.h>
#define maxn 2003
#define mod 1000000007
using namespace std;

int n,m;
int dpR[maxn];
int dpC[maxn];
int dpD[2*maxn];
char s[maxn][maxn];
int dp[maxn][maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%s",s[i]+1);
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ) {
			if(i == 1 && j == 1) {
				dp[i][j] = 1;
				dpR[i] = (dpR[i] + dp[i][j]) % mod;
				dpC[j] = (dpC[j] + dp[i][j]) % mod;
				dpD[i-j+m] = (dpD[i-j+m] + dp[i][j]) % mod;
			}
			else if(s[i][j] == '.') {
				dp[i][j] = (dp[i][j] + dpR[i]) % mod;
				dp[i][j] = (dp[i][j] + dpC[j]) % mod;
				dp[i][j] = (dp[i][j] + dpD[i-j+m]) % mod;
				dpR[i] = (dpR[i] + dp[i][j]) % mod;
				dpC[j] = (dpC[j] + dp[i][j]) % mod;
				dpD[i-j+m] = (dpD[i-j+m] + dp[i][j]) % mod;
			}
			else {
				dp[i][j] = dpR[i] = dpC[j] = dpD[i-j+m] = 0;
			}
			//printf("dp[%d][%d] =  %d\n",i,j,dp[i][j]);
		}
	printf("%d\n",dp[n][m]);
	return 0;
}
