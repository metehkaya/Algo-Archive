#include <bits/stdc++.h>
#define maxn1 2001
#define maxn2 1001
#define mod 1000000007
using namespace std;
typedef long long LL;

int T,n,n1,n2;
int dp[maxn1][maxn2][2];
set<int> myset;

void reset() {
	n1 = n2 = 0;
	myset.clear();
}

int f(int n1, int n2, bool k) {
	if( dp[n1][n2][k] != -1 )
		return dp[n1][n2][k];
	if( n1 + 2*n2 == 0 )
		return dp[n1][n2][k] = 1;
	dp[n1][n2][k] = 0;
	if(n2)
		dp[n1][n2][k] = ( (LL) n2 * f(n1+1, n2-1, true) ) % mod;
	if(n1) {
		if(k)
			dp[n1][n2][k] += ( (LL) (n1-1) * f(n1-1, n2, false) ) % mod;
		else
			dp[n1][n2][k] += ( (LL) n1 * f(n1-1, n2, false) ) % mod;
		dp[n1][n2][k] %= mod;
	}
	return dp[n1][n2][k];
}

int main() {
	scanf("%d",&T);
	memset(dp, -1, sizeof(dp));
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		for( int i = 0 , x ; i < n ; i++ ) {
			scanf("%d",&x);
			if(myset.find(x) != myset.end())
				n2++;
			else
				myset.insert(x);
		}
		n1 = n - 2*n2;
		printf("%d\n",f(n1,n2,false));
	}
	return 0;
}
