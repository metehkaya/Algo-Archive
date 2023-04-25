#include <bits/stdc++.h>
using namespace std;

struct data {
	int a,b,c,d;
};

data getData( int _a , int _b , int _c , int _d ) {
	data tmp;
	tmp.a = _a;
	tmp.b = _b;
	tmp.c = _c;
	tmp.d = _d;
	return tmp;
}

data multMat( data x , data y ) {
	data z;
	z.a = ( x.a * y.a ) % 10 + ( x.b * y.c ) % 10;
	z.a %= 10;
	z.b = ( x.a * y.b ) % 10 + ( x.b * y.d ) % 10;
	z.b %= 10;
	z.c = ( x.c * y.a ) % 10 + ( x.d * y.c ) % 10;
	z.c %= 10;
	z.d = ( x.c * y.b ) % 10 + ( x.d * y.d ) % 10;
	z.d %= 10;
	return z;
}

int T,n;
data mat[30];

int main() {
	
	mat[0] = getData( 1 , 1 , 1 , 0 );
	for( int i = 1 ; i < 30 ; i++ )
		mat[i] = multMat( mat[i-1] , mat[i-1] );
	
	scanf( "%d" , &T );
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf( "%d" , &n );
		data res = getData( 1 , 0 , 0 , 1 );
		for( int i = 0 ; i < 30 ; i++ )
			if( n & (1 << i) )
				res = multMat( res , mat[i] );
		printf( "%d\n" , res.a );
	}
	
	return 0;

}
