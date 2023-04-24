#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T,n;
LL sum,ans;
LL times[95];
int primes[95];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		ans = sum = 0;
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d%lld",&primes[i],&times[i]);
			sum += times[i]*primes[i];
		}
		for( LL X = sum-1 ; X >= max(sum-29940,1ll) ; X-- ) {
			LL x = X;
			int cnt[n];
			memset(cnt,0,sizeof(cnt));
			for( int i = 0 ; i < n ; i++ )
				while(x % primes[i] == 0) {
					cnt[i]++;
					x /= primes[i];
				}
			if(x != 1)
				continue;
			bool exceeds = false;
			for( int i = 0 ; i < n ; i++ )
				if(cnt[i] > times[i])
					exceeds = true;
			if(exceeds)
				continue;
			LL group1 = 0;
			for( int i = 0 ; i < n ; i++ )
				group1 += primes[i] * (times[i] - cnt[i]);
			if(group1 == X) {
				ans = X;
				break;
			}
		}
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
