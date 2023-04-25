#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
typedef long long LL;

int n,m;
LL ar[maxn];

int main() {
	scanf( "%d" , &n );
	for( int i = 0 ; i < n ; i++ )
		scanf( "%lld" , &ar[i] );
	scanf( "%d" , &m );
	for( int j = 0 ; j < m ; j++ ) {
		LL q;
		scanf( "%lld" , &q );
		LL orr = 0;
		for( int i = 0 ; i < n ; i++ ) {
			LL x = (orr | ar[i]);
			LL y = q;
			LL z = (x ^ y);
			if( z == (z & y) )
				orr = x;
		}
		if( orr == q )
			puts( "YES" );
		else
			puts( "NO" );
	}
	return 0;
}