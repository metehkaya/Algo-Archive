#include <bits/stdc++.h>
#define maxn 100003
using namespace std;

int n,k;
int t[maxn];
int x[maxn];
int y[maxn];
int dp[maxn];
int mx[maxn];

int main() {
	scanf("%d%d",&k,&n);
	t[0] = 0 , x[0] = y[0] = 1;
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
	memset(dp,-1,sizeof(dp));
	memset(mx,-1,sizeof(mx));
	dp[0] = mx[0] = 0;
	for( int i = 1 ; i <= n ; i++ ) {
		for( int j = max(i-2*k,0) ; j < i ; j++ )
			if( dp[j] != -1 && abs(x[i]-x[j]) + abs(y[i]-y[j]) <= t[i]-t[j] )
				dp[i] = max(dp[i],dp[j]+1);
		if(i >= 2*k)
			dp[i] = max(dp[i],mx[i-2*k]+1);
		mx[i] = max(mx[i-1],dp[i]);
	}
	printf("%d\n",mx[n]);
	return 0;
}
