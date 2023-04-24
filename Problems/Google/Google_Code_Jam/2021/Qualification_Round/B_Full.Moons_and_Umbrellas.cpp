#include <bits/stdc++.h>
#define maxn 1003
using namespace std;

int T,n,x,y;
char s[maxn];
int dp[maxn][2];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%s",&x,&y,s);
		n = strlen(s);
		if(s[0] == 'C' || s[0] == '?')
			dp[0][0] = 0;
		else
			dp[0][0] = INT_MAX;
		if(s[0] == 'J' || s[0] == '?')
			dp[0][1] = 0;
		else
			dp[0][1] = INT_MAX;
		for( int i = 1 ; i < n ; i++ ) {
			dp[i][0] = dp[i][1] = INT_MAX;
			if(s[i] == 'C' || s[i] == '?') {
				if(dp[i-1][0] != INT_MAX)
					dp[i][0] = min(dp[i][0],dp[i-1][0]);
				if(dp[i-1][1] != INT_MAX)
					dp[i][0] = min(dp[i][0],dp[i-1][1]+y);
			}
			if(s[i] == 'J' || s[i] == '?') {
				if(dp[i-1][1] != INT_MAX)
					dp[i][1] = min(dp[i][1],dp[i-1][1]);
				if(dp[i-1][0] != INT_MAX)
					dp[i][1] = min(dp[i][1],dp[i-1][0]+x);
			}
		}
		int ans = min(dp[n-1][0],dp[n-1][1]);
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
