#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n;
int ans;

int main() {
	scanf("%lld",&n);
	for( LL i = 1 ; i*i <= n ; i++ )
		if(n%i == 0) {
			if(i%2)
				ans++;
			if((n/i)%2 && i*i < n)
				ans++;
		}
	n *= 2;
	for( LL i = 1 ; i*i <= n ; i++ )
		if(n%i == 0)
			if(i%2 + (n/i)%2 == 1)
				ans++;
	printf("%d\n",ans);
	return 0;
}
