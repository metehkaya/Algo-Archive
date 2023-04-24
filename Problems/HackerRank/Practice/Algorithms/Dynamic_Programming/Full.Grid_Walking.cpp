#include <bits/stdc++.h>
#define maxn 11
#define maxd 101
#define maxm 301
#define mod 1000000007
using namespace std;
typedef long long LL;

int T,n,m;
int x[maxn];
int d[maxn];
int dp[maxn][maxm];
int comb[maxm][maxm];
int dpSub[maxn][maxm][maxd];

int g(int id, int rem, int pos) {
	if( dpSub[id][rem][pos] != -1 )
		return dpSub[id][rem][pos];
	if( rem == 0 )
		return dpSub[id][rem][pos] = 1;
	dpSub[id][rem][pos] = 0;
	if(pos>1)
		dpSub[id][rem][pos] = ( dpSub[id][rem][pos] + g(id,rem-1,pos-1) ) % mod;
	if(pos<d[id])
		dpSub[id][rem][pos] = ( dpSub[id][rem][pos] + g(id,rem-1,pos+1) ) % mod;
	return dpSub[id][rem][pos];
}

int f(int id, int rem) {
	if( rem == 0 )
		return 1;
	if( id == n+1 )
		return 0;
	if( dp[id][rem] != -1 )
		return dp[id][rem];
	dp[id][rem] = 0;
	for( int i = 0 ; i <= rem ; i++ ) {
		LL tmp = (LL) comb[rem][i] * dpSub[id][i][x[id]];
		tmp %= mod;
		tmp *= (LL) f(id+1, rem-i);
		tmp %= mod;
		dp[id][rem] = ( dp[id][rem] + tmp ) % mod;
	}
	return dp[id][rem];
}

int main() {
	scanf("%d",&T);
	for( int i = 0 ; i < maxm ; i++ )
		comb[i][0] = 1;
	for( int i = 1 ; i < maxm ; i++ )
		for( int j = 1 ; j <= i ; j++ )
			comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&m);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&x[i]);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&d[i]);
		memset(dp,-1,sizeof(dp));
		memset(dpSub,-1,sizeof(dpSub));
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 0 ; j <= m ; j++ )
				g(i,j,x[i]);
		printf("%d\n",f(1,m));
	}
}
