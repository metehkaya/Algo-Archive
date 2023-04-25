#include <bits/stdc++.h>
using namespace std;

int n;
int ans[20];
int hashh[256];
bool mark[32][5][32][5][20][20];
string str;

void g() {
	for( int i = 0 ; i < n ; i++ )
		printf( "%d " , ans[i] );
	exit(0);
}

void f( int c1 , int v1 , int c2 , int v2 , int t1 , int t2 ) {
	if( t1 + t2 == n ) {
		if( t1 == t2 )
			g();
		return;
	}
	if( mark[c1][v1][c2][v2][t1][t2] )
		return;
	mark[c1][v1][c2][v2][t1][t2] = true;
	int val = hashh[ str[t1+t2] ];
	if( val <= 2 ) {
		if( v1 < n / 4 && t1 < n / 2 - 1 ) {
			ans[t1+t2] = 1;
			f( c1 + ( (val-1) << v1 ) , v1 + 1 , c2 , v2 , t1 + 1 , t2 );
		}
		if( v2 < n / 4 && t2 < n / 2 - 1 ) {
			ans[t1+t2] = 2;
			f( c1 , v1 , c2 + ( (val-1) << v2 ) , v2 + 1 , t1 , t2 + 1 );
		}
	}
	else {
		if( v1 && t1 < n / 2 ) {
			int v = v1 - 1;
			int divv = c1 / (1 << v);
			if( val + divv == 4 ) {
				ans[t1+t2] = 1;
				f( c1 - (divv << v) , v1 - 1 , c2 , v2 , t1 + 1 , t2 );
			}
		}
		if( v2 && t2 < n / 2 ) {
			int v = v2 - 1;
			int divv = c2 / (1 << v);
			if( val + divv == 4 ) {
				ans[t1+t2] = 2;
				f( c1 , v1 , c2 - (divv << v) , v2 - 1 , t1 , t2 + 1 );
			}
		}
	}
}

int main() {
	hashh['('] = 1 , hashh['['] = 2;
	hashh[')'] = 4 , hashh[']'] = 3;
	cin >> str;
	n = str.length();
	if( n % 4 ) {
		puts( "impossible" );
		return 0;
	}
	f( 0 , 0 , 0 , 0 , 0 , 0 );
	puts( "impossible" );
	return 0;
}