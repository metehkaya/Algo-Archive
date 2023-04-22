#include <bits/stdc++.h>
#define maxn 100002
using namespace std;

int T,n;
char a[maxn];
char b[maxn];
int dp[maxn][2];
int cnt[maxn][2];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int f(int s , int e , int ch , int k) {
	dp[s-ch][k] = 0;
	cnt[s-ch][k] = 0;
	for( int i = s ; i != e+ch ; i += ch )
		cnt[i][k] = cnt[i-ch][k] + ( (i == s) || (b[i] != b[i-ch]) );
	for( int i = s ; i != e+ch ; i += ch )
		if(a[i] == b[i])
			dp[i][k] = dp[i-ch][k];
		else
			dp[i][k] = cnt[i][k];
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%s%s",&n,a+1,b+1);
		f(1,n,+1,0);
		f(n,1,-1,1);
		int ans = INT_MAX;
		for( int i = 0 ; i <= n ; i++ )
			ans = min( ans , max( dp[i][0] , dp[i+1][1] ) );
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
