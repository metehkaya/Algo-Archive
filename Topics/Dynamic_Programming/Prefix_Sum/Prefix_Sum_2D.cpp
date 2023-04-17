#include <bits/stdc++.h>
#define maxn 1003
using namespace std;
typedef long long LL;

int n,m,q;
int ar[maxn][maxn];
LL sum[maxn][maxn];

int main() {
	scanf("%d%d%d",&n,&m,&q);
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ) {
			scanf("%d",&ar[i][j]);
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + ar[i][j];
		}
	while(q--) {
		int r1,c1,r2,c2;
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		LL ans = sum[r2][c2];
		ans -= sum[r1-1][c2] + sum[r2][c1-1];
		ans += sum[r1-1][c1-1];
		printf("%lld\n",ans);
	}
	return 0;
}
