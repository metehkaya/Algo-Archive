#include <bits/stdc++.h>
#define maxn 51
#define mod 1000000007
using namespace std;
typedef long long LL;

int T,n,k;
int dp[maxn][maxn];
int dpNext[maxn][maxn];

LL getPow(LL x , LL y) {
	if(y == 0)
		return 1;
	LL res = getPow(x,y/2);
	res = res*res % mod;
	if(y & 1)
		res = res*x % mod;
	return res;
}

LL getInv(LL x) {
	return getPow(x,mod-2);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		memset(dp,0,sizeof(dp));
		dp[n][0] = 1;
		LL q = 1;
		for( LL m = n*(n-1)/2 ; m >= 1 ; m-- ) {
			q = q*m % mod;
			memset(dpNext,0,sizeof(dpNext));
			for( int i = 0 ; i <= n ; i++ )
				for( int j = 0 ; j <= n ; j++ )
					if(dp[i][j]) {
						LL w1 = i*(i-1)/2;
						LL w2 = i*(n-i);
						LL w3 = m-w1-w2;
						if(i >= 2)
							dpNext[i-2][j+1] = (dpNext[i-2][j+1] + dp[i][j]*w1) % mod;
						if(i >= 1 && j >= 1)
							dpNext[i-1][j] = (dpNext[i-1][j] + dp[i][j]*w2) % mod;
						if(j >= 1)
							dpNext[i][j] = (dpNext[i][j] + dp[i][j]*w3) % mod;
					}
			for( int i = 0 ; i <= n ; i++ )
				for( int j = 0 ; j <= n ; j++ )
					dp[i][j] = dpNext[i][j];
		}
		LL p = 0;
		for( int i = 0 ; i <= k ; i++ )
			p = (p + dp[i][k-i]) % mod;
		LL ans = p * getInv(q) % mod;
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
