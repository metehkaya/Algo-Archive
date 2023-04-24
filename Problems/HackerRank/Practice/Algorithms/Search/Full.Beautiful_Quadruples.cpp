#include <bits/stdc++.h>
#define maxn 3002
#define maxv 4096
using namespace std;
typedef long long LL;

LL ans;
LL dp[maxn][maxv];
int ar[4];

int main() {
	for( int i = 0 ; i < 4 ; i++ )
		scanf("%d",&ar[i]);
	sort(ar, ar+4);
	for( int i = 1 ; i <= ar[0] ; i++ )
		for( int j = i ; j <= ar[1] ; j++ ) {
			int vmin = ar[3]-ar[2]+1;
			int vmax = ar[3]-j+1;
			LL sum = (LL) (vmax+vmin) * (vmax-vmin+1) / 2;
			ans += sum;
		}
	for( int i = ar[2] ; i >= 1 ; i-- ) {
		for( int j = 0 ; j < maxv ; j++ )
			dp[i][j] = dp[i+1][j];
		for( int j = i ; j <= ar[3] ; j++ ) {
			int val = i^j;
			dp[i][val]++;
		}
	}
	for( int i = 1 ; i <= ar[0] ; i++ )
		for( int j = i ; j <= ar[1] ; j++ )
			ans -= dp[j][i^j];
	printf("%lld\n",ans);
	return 0;
}
