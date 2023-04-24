#include <bits/stdc++.h>
using namespace std;

const int N = 51;

int T,n;
int cnt[N];
int mx[N][N][N][N];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		memset(mx, 0, sizeof(mx));
		memset(cnt, 0, sizeof(cnt));
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 1 ; j <= n ; j++ )
				for( int k = 1 ; k <= n ; k++ ) {
					scanf("%d",&mx[1][i][j][k]);
					cnt[1] += mx[1][i][j][k] == 1;
				}
		for( int len = 2 ; len <= n ; len++ )
			for( int i = 1 ; i <= n-len+1 ; i++ )
				for( int j = 1 ; j <= n-len+1 ; j++ )
					for( int k = 1 ; k <= n-len+1 ; k++ ) {
						for( int t = 0 ; t < 8 ; t++ ) {
							int i1 = (t&1) >> 0;
							int j1 = (t&2) >> 1;
							int k1 = (t&4) >> 2;
							mx[len][i][j][k] = max(mx[len][i][j][k], mx[len-1][i+i1][j+j1][k+k1]);
						}
						cnt[len] += mx[len][i][j][k] == len;
					}
		for( int i = 1 ; i <= n ; i++ )
			printf("%d ", cnt[i]);
		puts("");
	}
	return 0;
}
