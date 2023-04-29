#include <bits/stdc++.h>
#define maxs 1234567890LL
#define maxs2 1234572895LL
using namespace std;
typedef long long LL;

LL n,k,res,cnt;
vector<LL> dp;

int main() {
	while(true) {
		scanf("%lld%lld",&n,&k);
		if(n == 0)
			break;
		k = min(k,30LL);
		n--;
		if(k == 0) {
			printf("%lld\n",min(n,maxs+1));
			continue;
		}
		else if(k == 1) {
			printf("%lld\n",min(n*(n+1)/2,maxs2));
			continue;
		}
		res = 0;
		cnt = 1;
		dp.clear();
		dp.resize(k+1,0);
		dp[0] = 1;
		for( LL i = 1 ; i <= n ; i++ ) {
			vector<LL> row(k+1,0);
			for( int j = 0 ; j < k ; j++ )
				row[0] += dp[j];
			row[k] = dp[k] + dp[k-1];
			for( int j = 1 ; j < k ; j++ )
				row[j] = dp[j-1];
			dp = row;
			res += cnt;
			cnt += dp[0];
			if(res > maxs)
				break;
		}
		printf("%lld\n",res);
	}
	return 0;
}
