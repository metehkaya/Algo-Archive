#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
typedef long long LL;

int T,n;
int ar[maxn];
LL dp[maxn][2];

LL f(int index, bool k) {
	if(index == n)
		return 0;
	if(dp[index][k] != -1)
		return dp[index][k];
	if(!k) {
		dp[index][k] = (1LL << 60);
		for( int i = index ; i < min(index+3,n) ; i++ )
			dp[index][k] = min(dp[index][k], f(i+1, true));
	}
	else {
		LL sum = 0;
		for( int i = index ; i < min(index+3,n) ; i++ ) {
			sum += ar[i];
			dp[index][k] = max(dp[index][k], f(i+1, false)+sum);
		}
	}
	return dp[index][k];
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&ar[i]);
		memset(dp,-1,sizeof(dp));
		printf("%lld\n",f(0,true));
	}
	return 0;
}
