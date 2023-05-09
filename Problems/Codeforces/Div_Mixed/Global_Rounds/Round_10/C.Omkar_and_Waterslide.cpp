#include <bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long LL;

int T,n;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&ar[i]);
		LL ans = 0;
		for( int i = 1 ; i < n ; i++ )
			ans += max(ar[i-1]-ar[i],0);
		printf("%lld\n",ans);
	}
	return 0;
}
