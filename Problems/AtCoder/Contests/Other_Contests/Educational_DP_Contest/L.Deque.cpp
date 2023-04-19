#include <bits/stdc++.h>
#define maxn 3002
using namespace std;
typedef long long LL;

int n;
int ar[maxn];
LL dp[maxn][maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	for( int len = 1 ; len <= n ; len++ )
		for( int i = 1 ; i <= n-len+1 ; i++ ) {
			int j = i+len-1;
			dp[i][j] = max( ar[i]-dp[i+1][j] , ar[j]-dp[i][j-1] );
		}
	printf("%lld\n",dp[1][n]);
	return 0;
}
