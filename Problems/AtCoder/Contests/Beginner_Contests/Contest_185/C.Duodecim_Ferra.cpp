#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
LL ans = 1;

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= 11 ; i++ )
		ans = (ans * (n-12+i) / i);
	printf("%lld\n",ans);
	return 0;
}
