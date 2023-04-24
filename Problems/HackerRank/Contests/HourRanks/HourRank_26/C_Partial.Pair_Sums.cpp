#include <bits/stdc++.h>
#define maxn 200003
using namespace std;
typedef long long LL;

int n;
LL ans;
int a[maxn];
LL sum[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&a[i]);
		sum[i] = sum[i-1] + a[i];
	}
	for( int i = 1 ; i <= n ; i++ ) {
		LL tot = 0;
		for( int j = i+1 ; j <= n ; j++ ) {
			tot += a[j] * (sum[j-1]-sum[i-1]);
			ans = max(ans,tot);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
