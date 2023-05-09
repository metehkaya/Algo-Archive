#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
typedef long long LL;

int T,n,k;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		sort(ar+1,ar+n+1);
		LL ans = 0;
		for( int i = n ; i >= n-k ; i-- )
			ans += ar[i];
		printf("%lld\n",ans);
	}
	return 0;
}
