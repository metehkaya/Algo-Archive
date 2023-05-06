#include <bits/stdc++.h>
#define maxn 100001
using namespace std;
typedef long long LL;

int T,n,k;
int ar[maxn];
LL sum[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		LL left = 0 , right = 0;
		for( int i = 1 ; i <= n ; i++ ) {
			scanf("%d",&ar[i]);
			sum[i] = sum[i-1] + ar[i];
			left += ar[i] % k;
		}
		LL ans = left;
		for( int i = n-1 ; i >= 1 ; i-- ) {
			left -= ar[i+1] % k;
			right += ( k - (ar[i+1] % k) ) % k;
			if( sum[i] >= right ) {
				if( left >= right )
					ans = min(ans, left-right);
				else
					ans = min(ans, (k - (right-left) % k) % k);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
