#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;

int T,n;
int dp[maxn];
int dp2[maxn];

void f(int x , int y) {
	int k = x/y-1;
	if(dp2[k] != -1)
		dp2[x] = max(dp2[x],dp2[k]+1);
	if(y > 2 && dp2[k] != -1)
		dp[x] = max(dp[x],dp2[k]+1);
}

int main() {
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	dp[0] = dp2[0] = 0;
	dp2[2] = 1;
	for( int i = 3 ; i < maxn ; i++ ) {
		dp[i] = dp2[i] = 1;
		for( int j = 2 ; j*j <= i ; j++ )
			if(i % j == 0) {
				f(i,j);
				f(i,i/j);
			}
	}
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		printf("Case #%d: %d\n",tc,dp[n]);
	}
	return 0;
}
