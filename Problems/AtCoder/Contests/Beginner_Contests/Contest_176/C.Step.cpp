#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,mx;
LL ans;

int main() {
	scanf("%d",&n);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		if(x < mx)
			ans += mx-x;
		else
			mx = x;
	}
	printf("%lld\n",ans);
	return 0;
}
