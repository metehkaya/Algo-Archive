#include <bits/stdc++.h>
#define maxn 1003
#define maxm 10003
using namespace std;

int n,m,ans;
int v[maxn];
int w[maxn];
int dp[maxm];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d%d",&v[i],&w[i]);
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	for( int i = 1 ; i <= n ; i++ ) {
		int j_max = m-w[i];
		for( int j = j_max ; j >= 0 ; j-- )
			if(dp[j] != -1) {
				int j_new = j+w[i];
				int v_new = dp[j]+v[i];
				dp[j_new] = max(dp[j_new],v_new);
			}
	}
	for( int i = 1 ; i <= m ; i++ )
		ans = max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}
