#include <bits/stdc++.h>
#define mod 1000000007LL
using namespace std;
typedef long long LL;

int n;
LL ans,sum;

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		LL x;
		scanf("%lld",&x);
		ans += sum*x;
		ans %= mod;
		sum += x;
		sum %= mod;
	}
	printf("%lld\n",ans);
	return 0;
}
