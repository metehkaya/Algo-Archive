#include <bits/stdc++.h>
#define maxn 101
using namespace std;

int a,b,c;
double dp[maxn][maxn][maxn];

int main() {
	for( int i = 99 ; i >= 0 ; i-- )
		for( int j = 99 ; j >= 0 ; j-- )
			for( int k = 99 ; k >= 0 ; k-- ) {
				int sum = i+j+k;
				dp[i][j][k] += (double) i / sum * (dp[i+1][j][k] + 1);
				dp[i][j][k] += (double) j / sum * (dp[i][j+1][k] + 1);
				dp[i][j][k] += (double) k / sum * (dp[i][j][k+1] + 1);
			}
	cin >> a >> b >> c;
	printf("%.10lf\n",dp[a][b][c]);
	return 0;
}
