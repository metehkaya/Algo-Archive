#include <bits/stdc++.h>
#define maxn 101
using namespace std;
typedef long long LL;

LL x;
int n;
int ar[maxn];
int dp[maxn][maxn];

int main() {
	scanf("%d%lld",&n,&x);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	LL ans = LLONG_MAX;
	for( int k = 1 ; k <= n ; k++ ) {
		memset(dp,-1,sizeof(dp));
		dp[0][0] = 0;
		for( int i = 1 ; i <= n ; i++ )
			for( int j = k-1 ; j >= 0 ; j-- )
				for( int l = 0 ; l < k ; l++ )
					if(dp[j][l] != -1) {
						int val = dp[j][l] + ar[i];
						int p = val % k;
						dp[j+1][p] = max(dp[j+1][p],val);
					}
		int p = x%k;
		if(dp[k][p] != -1)
			ans = min(ans,(x-dp[k][p])/k);
	}
	printf("%lld\n",ans);
	return 0;
}
