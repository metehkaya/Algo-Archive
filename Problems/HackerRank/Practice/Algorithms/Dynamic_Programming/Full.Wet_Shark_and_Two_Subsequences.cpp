#include <bits/stdc++.h>
#define maxn 101
#define maxa 2001
#define mod 1000000007
using namespace std;
typedef long long LL;

int n,r,s,a,b,ans;
int ar[maxn];
int dp[maxn][maxa];

int main() {
	scanf("%d%d%d",&n,&r,&s);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	if( r<s || r%2 != s%2 ) {
		puts("0");
		return 0;
	}
	a = (r+s)/2;
	b = (r-s)/2;
	dp[0][0] = 1;
	for( int i = 1 ; i <= n ; i++ )
		for( int k = i ; k >= 1 ; k-- )
			for( int j = ar[i] ; j <= a ; j++ )
				dp[k][j] = ( dp[k][j] + dp[k-1][j-ar[i]] ) % mod;
	for( int i = 0 ; i <= n ; i++ )
		ans = ( ans + ( (LL) dp[i][a] * dp[i][b] ) % mod ) % mod;
	printf("%d\n",ans);
	return 0;
}
