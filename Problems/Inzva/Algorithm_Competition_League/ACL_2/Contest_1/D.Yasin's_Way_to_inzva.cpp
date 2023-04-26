#include <bits/stdc++.h>
#define maxn 1000
using namespace std;
typedef long long LL;

int n,m;
LL ar[maxn][maxn];

bool check(LL add) {
	LL dp[n][m];
	memset(dp,-1,sizeof(dp));
	dp[0][0] = add+ar[0][0];
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			if(dp[i][j] >= 0) {
				if(i < n-1)
					dp[i+1][j] = max(dp[i+1][j] , dp[i][j] + ar[i+1][j]);
				if(j < m-1)
					dp[i][j+1] = max(dp[i][j+1] , dp[i][j] + ar[i][j+1]);
			}
	return dp[n-1][m-1] >= 0;
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , r , c ; i < n*m ; i++ ) {
		LL v;
		string s;
		cin >> r >> c >> s >> v;
		if(s == "M")
			ar[r][c] = v;
		else
			ar[r][c] = -v;
	}
	LL l = 0 , r = LLONG_MAX , ans = LLONG_MAX;
	while(l <= r) {
		LL mid = (l+r) >> 1;
		if(check(mid))
			ans = mid , r = mid-1;
		else
			l = mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}