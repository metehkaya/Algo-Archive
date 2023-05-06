#include <bits/stdc++.h>
#define maxn 10000
using namespace std;
typedef long long LL;

int T,n;
int a[maxn];
int b[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&a[i]);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&b[i]);
		sort(a, a+n);
		sort(b, b+n);
		LL ans = 0;
		for( int i = 0 ; i < n ; i++ )
			ans += min(a[i], b[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
