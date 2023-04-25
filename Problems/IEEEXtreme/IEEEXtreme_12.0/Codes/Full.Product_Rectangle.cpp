#include <bits/stdc++.h>
#define maxn 2003
using namespace std;
typedef long long LL;

int n,m;
LL ans;
LL a[maxn];
LL b[maxn];

void f() {
	LL sumA = 0 , bestA = a[1];
	for( int i = 1 , j = 1 ; i <= n ; i = j ) {
		sumA = 0;
		while( j <= n && sumA >= 0 ) {
			sumA += a[j++];
			bestA = max( bestA , sumA );
		}
	}
	LL sumB = 0 , bestB = b[1];
	for( int i = 1 , j = 1 ; i <= m ; i = j ) {
		sumB = 0;
		while( j <= m && sumB >= 0 ) {
			sumB += b[j++];
			bestB = max( bestB , sumB );
		}
	}
	ans = max( ans , bestA * bestB );
}

int main() {
	scanf( "%d%d" , &n , &m );
	for( int i = 1 ; i <= n ; i++ )
		scanf( "%lld" , &a[i] );
	for( int i = 1 ; i <= m ; i++ )
		scanf( "%lld" , &b[i] );
	ans = a[1] * b[1];
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ )
			ans = max( ans , a[i] * b[j] );
	f();
	for( int i = 1 ; i <= n ; i++ )
		a[i] *= -1;
	for( int i = 1 ; i <= m ; i++ )
		b[i] *= -1;
	f();
	printf( "%lld\n" , ans );
	return 0;
}