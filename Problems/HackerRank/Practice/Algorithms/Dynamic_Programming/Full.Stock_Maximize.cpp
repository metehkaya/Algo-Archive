#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100001
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int T,n;
pi ar[maxn];
LL sum[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ ) {
			scanf("%d",&ar[i].fi);
			ar[i].se = i;
			sum[i] = sum[i-1] + ar[i].fi;
		}
		LL ans = 0;
		sort( ar+1 , ar+n+1 );
		for( int i = n , last = 0 ; i >= 1 ; i-- ) {
			int val = ar[i].fi;
			int index = ar[i].se;
			if( index < last )
				continue;
			ans -= sum[index] - sum[last];
			ans += (LL) val * (index-last);
			last = index;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
