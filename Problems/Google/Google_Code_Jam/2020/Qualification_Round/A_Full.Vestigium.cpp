#include <bits/stdc++.h>
#define maxn 100
using namespace std;

int T,n;
bool var[maxn];
int ar[maxn][maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < n ; j++ )
				scanf("%d",&ar[i][j]);
		int sum, row, col;
		sum = row = col = 0;
		for( int i = 0 ; i < n ; i++ )
			sum += ar[i][i];
		for( int i = 0 ; i < n ; i++ ) {
			memset(var, false, sizeof(var));
			bool add = false;
			for( int j = 0 ; j < n ; j++ ) {
				if(var[ar[i][j]-1])
					add = true;
				var[ar[i][j]-1] = true;
			}
			row += add;
		}
		for( int j = 0 ; j < n ; j++ ) {
			memset(var, false, sizeof(var));
			bool add = false;
			for( int i = 0 ; i < n ; i++ ) {
				if(var[ar[i][j]-1])
					add = true;
				var[ar[i][j]-1] = true;
			}
			col += add;
		}
		printf("Case #%d: %d %d %d\n",tc,sum,row,col);
	}
	return 0;
}
