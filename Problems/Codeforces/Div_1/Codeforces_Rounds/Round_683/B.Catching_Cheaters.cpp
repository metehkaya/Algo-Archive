#include <bits/stdc++.h>
#define maxn 5001
using namespace std;

int n,m,ans;
string s,t;
int dp[maxn][maxn];

int main() {
	cin >> n >> m >> s >> t;
	for( int i = 0 ; i <= n ; i++ )
		for( int j = 0 ; j <= m ; j++ )
			if(i > 0 || j > 0) {
				if(i > 0)
					dp[i][j] = max(dp[i][j],dp[i-1][j]-1);
				if(j > 0)
					dp[i][j] = max(dp[i][j],dp[i][j-1]-1);
				if(i > 0 && j > 0 && s[i-1] == t[j-1])
					dp[i][j] = max(dp[i][j],dp[i-1][j-1]+2);
				ans = max(ans,dp[i][j]);
			}
	printf("%d\n",ans);
	return 0;
}
