#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL T,n,m,s,d1,d2;

LL g( LL x ) {
	if( x % 4 == 0 )
		return x;
	else if( x % 4 == 1 )
		return 1;
	else if( x % 4 == 2 )
		return x + 1;
	else
		return 0;
}

LL f( LL x , LL y ) {
	return g( y ) ^ g( x - 1 );
}

int main() {
	
	scanf( "%lld" , &T );
	
	for( LL tc = 1 ; tc <= T ; tc++ ) {
		
		LL ans = 0;
		scanf( "%lld%lld%lld%lld%lld" , &m , &n , &s , &d1 , &d2 );
		
		for( LL i = 0 ; i < n ; i++ )
			ans ^= f( s + i * m , s + i * m + m - 1 );
		
		LL diff , d3 = d1 - s , d4 = d2 - s;
		if( d3 % m > d4 % m ) {
			LL dif = d3 % m - d4 % m + 1;
			d1 -= dif - 1;
			d2 += dif - 1;
			d3 = d1 - s;
			d4 = d2 - s;
		}
		
		diff = d4 % m - d3 % m + 1;
		for( LL i = 0 ; true ; i++ ) {
			if( d1 + m * i > d2 )
				break;
			ans ^= f( d1 + m * i , d1 + m * i + diff - 1 );
		}
		
		printf( "%lld\n" , ans );
		
	}
	
	return 0;

}
