#include <bits/stdc++.h>
#define maxn 1000
using namespace std;
typedef long long LL;

int T,n;
LL d;
LL a[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%lld",&n,&d);
		for( int i = 0 ; i < n ; i++ )
			scanf("%lld",&a[i]);
		for( int i = n-1 ; i >= 0 ; i-- )
			d = a[i] * ( d / a[i] );
		printf("Case #%d: %lld\n",tc,d);
	}
	return 0;
}
