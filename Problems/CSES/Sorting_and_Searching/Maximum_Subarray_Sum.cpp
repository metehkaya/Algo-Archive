#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
LL ans,sum;

int main() {
	scanf("%d",&n);
	ans = INT_MIN;
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		sum += x;
		ans = max(ans,sum);
		sum = max(sum,0LL);
	}
	printf("%lld\n",ans);
	return 0;
}