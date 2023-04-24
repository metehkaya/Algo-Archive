#include <bits/stdc++.h>
#define maxn 383
using namespace std;

const int INF = (int) 1e9;

int n,m,k,ans;
int a[maxn][maxn];
int b[maxn][maxn];
int sum[maxn][maxn];

void read() {
	ans = -INF;
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ )
			scanf("%d",&a[i][j]);
}

void f1() {
	int best_sum = INF;
	int R,C,X;
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ) {
			int tot = 0;
			for( int x = 1 ; x <= k && j+x-1 <= m ; x++ ) {
				tot += a[i][j+x-1];
				if(tot <= best_sum) {
					best_sum = tot;
					R = i;
					C = j;
					X = x;
				}
			}
		}
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ )
			b[i][j] = a[i][j];
	for( int col = C ; col <= C+X-1 ; col++ )
		b[R][col] = 0;
}

void f2() {
	int best_sum = INF;
	int R,C,X;
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ) {
			int tot = 0;
			for( int x = 1 ; x <= k && i+x-1 <= n ; x++ ) {
				tot += a[i+x-1][j];
				if(tot <= best_sum) {
					best_sum = tot;
					R = i;
					C = j;
					X = x;
				}
			}
		}
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ )
			b[i][j] = a[i][j];
	for( int row = R ; row <= R+X-1 ; row++ )
		b[row][C] = 0;
}

void solve() {
	for( int col = 1 ; col <= m ; col++ )
		for( int row = 1 ; row <= n ; row++ )
			sum[col][row] = sum[col][row-1] + b[row][col];
	for( int r1 = 1 ; r1 <= n ; r1++ )
		for( int r2 = r1 ; r2 <= n ; r2++ ) {
			int tot = 0;
			for( int col = 1 ; col <= m ; col++ ) {
				tot += sum[col][r2] - sum[col][r1-1];
				ans = max(ans,tot);
				tot = max(tot,0);
			}
		}
}

int main() {
	read();
	f1();
	solve();
	f2();
	solve();
	printf("%d\n",ans);
	return 0;
}
