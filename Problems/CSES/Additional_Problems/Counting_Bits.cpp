#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,ans,curr;

int main() {
	scanf("%lld",&n);
	for( int i = 49 ; i >= 0 ; i-- ) {
		int bit = (n & (1LL<<i)) > 0 ? 1 : 0;
		if(bit) {
			curr += (1LL<<i);
			if(i)
				ans += (1LL<<(i-1))*i;
			ans += n-curr+1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}