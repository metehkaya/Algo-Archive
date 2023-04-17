#include <bits/stdc++.h>
#define maxn 100003
#define mod 1000000007
using namespace std;

int n,m;
int dp[maxn];

int main() {
	scanf("%d",&m);
	dp[1] = 1;
	for( int i = 2 ; i < maxn ; i++ )
		dp[i] = (dp[i-1] + dp[i-2]) % mod;
	while(m--) {
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
	return 0;
}
