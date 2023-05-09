#include <bits/stdc++.h>
#define maxn 500003
#define mod 1000000007LL
using namespace std;
typedef long long LL;

int T,n;
int cnt[60];
LL ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 0 ; tc < T ; tc++ ) {
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%lld",&ar[i]);
			for( int j = 0 ; j < 60 ; j++ )
				if(ar[i]&(1ll<<j))
					cnt[j]++;
		}
		LL ans = 0;
		for( int i = 0 ; i < n ; i++ ) {
			LL x = 0 , y = 0;
			for( int j = 0 ; j < 60 ; j++ ) {
				if(ar[i]&(1ll<<j)) {
					x += (1ll<<j) % mod * cnt[j] % mod;
					y += (1ll<<j) % mod * n % mod;
					x %= mod;
					y %= mod;
				}
				else {
					y += (1ll<<j) % mod * cnt[j] % mod;
					y %= mod;
				}
			}
			ans = (ans + x*y) % mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
