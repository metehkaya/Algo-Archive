#include <bits/stdc++.h>
#define maxn 500003
using namespace std;
typedef long long LL;

int n,m;
LL dp[251];

int main() {
	dp[0] = 1;
	scanf("%d%d",&m,&n);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		for( int i = x ; i <= m ; i++ )
			dp[i] += dp[i-x];
	}
	printf("%lld\n",dp[m]);
	return 0;
}
