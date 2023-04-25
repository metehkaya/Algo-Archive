#include <bits/stdc++.h>
#define maxn 1000
#define maxk 1000000
using namespace std;

const int ADD1 = 2*maxn;
const int ADD2 = maxn-1;

int n,m,k;
int x[maxk];
int y[maxk];
int r[maxk];
int c[maxk];
int d[maxk];
int sum[4*maxn+1][4*maxn+1];

void read() {
	scanf( "%d%d%d" , &n , &m , &k );
	for( int i = 0 ; i < k ; i++ ) {
		scanf( "%d%d%d" , &r[i] , &c[i] , &d[i] );
		x[i] = r[i] - c[i];
		y[i] = r[i] + c[i];
	}
}

int changeX( int x ) {
	return x + ADD1;
}

int changeY( int y ) {
	return y + ADD2;
}

void preCalc() {
	for( int i = 0 ; i < k ; i++ ) {
		int x1 = changeX( x[i] - d[i] );
		int y1 = changeY( y[i] - d[i] );
		int x2 = changeX( x[i] + d[i] + 1 );
		int y2 = changeY( y[i] + d[i] + 1 );
		sum[x1][y1]++,sum[x2][y2]++;
		sum[x1][y2]--,sum[x2][y1]--;
	}
	for( int i = 1 ; i <= 4*maxn ; i++ )
		for( int j = 1 ; j <= 4*maxn ; j++ )
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
}

void solve() {
	int id = -1 , best = -1;
	for( int i = 0 ; i < k ; i++ ) {
		int x0 = changeX( x[i] );
		int y0 = changeY( y[i] );
		if( sum[x0][y0] - 1 > best ) {
			id = i + 1;
			best = sum[x0][y0] - 1;
		}
	}
	printf( "%d %d\n" , id , best );
}

int main() {
	read();
	preCalc();
	solve();
	return 0;
}
