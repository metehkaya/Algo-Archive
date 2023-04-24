#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int ar[10][10];
bool mark[10][10];

int dfs(int x, int y) {
	int cnt = 1;
	mark[x][y] = true;
	for( int i = -1 ; i <= +1 ; i++ )
		for( int j = -1 ; j <= +1 ; j++ ) {
			int tx = x+i , ty = y+j;
			if(tx < 0 || tx >= n || ty < 0 || ty >= m)
				continue;
			if(ar[tx][ty] != 1 || mark[tx][ty])
				continue;
			cnt += dfs(tx,ty);
		}
	return cnt;
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			scanf("%d",&ar[i][j]);
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < n ; j++ )
			if( ar[i][j] && !mark[i][j] )
				ans = max( ans , dfs(i,j) );
	printf("%d\n",ans);
	return 0;
}
