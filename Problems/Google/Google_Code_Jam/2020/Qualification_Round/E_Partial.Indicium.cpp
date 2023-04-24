#include <bits/stdc++.h>
using namespace std;

const int N = 5;

int T,n,k;
int ar[N][N];
int mat[N+1][N*N+1][N][N];

void output() {
	int sum = 0;
	for( int i = 0 ; i < n ; i++ )
		sum += ar[i][i]+1;
	if(mat[n][sum][0][0] == 0)
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < n ; j++ )
				mat[n][sum][i][j] = ar[i][j]+1;
}

void f(int row) {
	if(row == n-1) {
		for( int i = 0 ; i < n ; i++ ) {
			bool var[n];
			memset(var, false, sizeof(var));
			for( int oldRow = 0 ; oldRow < row ; oldRow++ )
				var[ar[oldRow][i]] = true;
			for( int val = 0 ; val < n ; val++ )
				if(!var[val])
					ar[row][i] = val;
		}
		output();
		return;
	}
	int a[n];
	for( int i = 0 ; i < n ; i++ )
		a[i] = i;
	do {
		bool cond = true;
		for( int i = 0 ; i < n ; i++ )
			for( int oldRow = 0 ; oldRow < row ; oldRow++ )
				if( a[i] == ar[oldRow][i] )
					cond = false;
		if(cond) {
			for( int i = 0 ; i < n ; i++ )
				ar[row][i] = a[i];
			f(row+1);
		}
	} while( next_permutation(a,a+n) );
}

int main() {
	for( n = 2 ; n <= 5 ; n++ )
		f(0);
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		printf("Case #%d: ",tc);
		if(mat[n][k][0][0] == 0)
			puts("IMPOSSIBLE");
		else {
			puts("POSSIBLE");
			for( int i = 0 ; i < n ; i++ , puts("") )
				for( int j = 0 ; j < n ; j++ )
					printf("%d ",mat[n][k][i][j]);
		}
	}
	return 0;
}
