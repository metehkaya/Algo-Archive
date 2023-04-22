#include <bits/stdc++.h>
#define maxn 21
#define maxs 10001
using namespace std;

int T;
double p;
double p1[maxn];
double p2[maxn];
double dp[maxs][maxn];
int comb[maxn][maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void init() {
	for( int i = 0 ; i < maxn ; i++ )
		comb[i][0] = 1;
	for( int i = 1 ; i < maxn ; i++ )
		for( int j = 1 ; j <= i ; j++ )
			comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
}

void reset() {
	memset(dp,0,sizeof(dp));
}

int main() {
	io();
	init();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%lf",&p);
		p1[0] = p2[0] = 1;
		for( int i = 1 ; i < maxn ; i++ )
			p1[i] = p1[i-1]*p , p2[i] = p2[i-1]*(1-p);
		dp[0][0] = 1;
		for( int s = 1 ; s < maxs ; s++ )
			for( int x = 0 ; x < maxn ; x++ )
				for( int i = 0 ; i <= x ; i++ )
					if(i || x < maxn-1)
						dp[s][x] += comb[20-(x-i)][i] * p1[i] * p2[20-x] * dp[s-1][x-i];
		double ans = 0;
		for( int s = 0 ; s < maxs ; s++ )
			ans += s*dp[s][20];
		printf("Case #%d: %.5lf\n",tc,ans);
	}
	return 0;
}
