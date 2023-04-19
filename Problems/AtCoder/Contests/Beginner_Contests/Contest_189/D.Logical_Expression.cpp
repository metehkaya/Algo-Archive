#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
LL dp[61][2];

int main() {
	scanf("%d",&n);
	dp[0][0] = dp[0][1] = 1;
	for( int s = 1 ; s <= n ; s++ ) {
		string str;
		cin >> str;
		for( int i = 0 ; i < 2 ; i++ )
			for( int j = 0 ; j < 2 ; j++ ) {
				int k;
				if(str == "AND")
					k = (i&j);
				else
					k = (i|j);
				dp[s][k] += dp[s-1][i];
			}
	}
	printf("%lld\n",dp[n][1]);
	return 0;
}
