#include <bits/stdc++.h>
#define maxn 301
using namespace std;

int n;
int cnt[3];
double dp[maxn][maxn][maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		cnt[x-1]++;
	}
	for( int c3 = 0 ; c3 <= n ; c3++ )
		for( int c2 = 0 ; c2 <= n-c3 ; c2++ )
			for( int c1 = 0 ; c1 <= n-c3-c2 ; c1++ )
				if( c1+c2+c3 ) {
					if(c3)
						dp[c3][c2][c1] += dp[c3-1][c2+1][c1] * c3 / n;
					if(c2)
						dp[c3][c2][c1] += dp[c3][c2-1][c1+1] * c2 / n;
					if(c1)
						dp[c3][c2][c1] += dp[c3][c2][c1-1] * c1 / n;
					dp[c3][c2][c1] += 1.0;
					dp[c3][c2][c1] *= (double) n / (c1+c2+c3);
				}
	printf("%.15lf\n",dp[cnt[2]][cnt[1]][cnt[0]]);
	return 0;
}
