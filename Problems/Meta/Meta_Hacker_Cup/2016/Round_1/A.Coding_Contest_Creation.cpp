#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int T,n;
int ar[maxn];
int dp[maxn][4];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&ar[i]);
		for( int i = 0 ; i < 4 ; i++ )
			dp[n-1][i] = 3-i;
		for( int i = n-2 ; i >= 0 ; i-- )
			for( int k = 0 ; k < 4 ; k++ ) {
				dp[i][k] = INT_MAX;
				int diff = ar[i+1]-ar[i];
				for( int st = k+1 ; st <= 3 ; st++ )
					if(st-k <= diff && diff <= 10*(st-k))
						dp[i][k] = min( dp[i][k] , dp[i+1][st] + st-k-1 );
				for( int st = 0 ; st < 4 ; st++ )
					if(ar[i+1] > st)
						dp[i][k] = min( dp[i][k] , dp[i+1][st] + 3-k+st );
			}
		int ans = INT_MAX;
		for( int i = 0 ; i < 4 ; i++ )
			ans = min( ans , dp[0][i] + i );
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
