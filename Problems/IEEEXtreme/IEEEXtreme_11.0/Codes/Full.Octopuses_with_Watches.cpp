#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int ff[9];
int ar[9][9];
int ar2[9][9];

void calc() {
	int cnt[m][3];
	memset( cnt , 0 , sizeof( cnt ) );
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ ) {
			ar2[i][j] = ( ar[i][j] + ff[i] ) % 3;
			cnt[j][ar2[i][j]]++;
		}
	int sum = 0;
	for( int i = 0 ; i < m ; i++ )
		sum += max( cnt[i][0] , max( cnt[i][1] , cnt[i][2] ) );
	ans = max( ans , sum );
}

void f( int ind ) {
	if( ind == n ) {
		calc();
		return;
	}
	for( int i = 0 ; i < 3 ; i++ ) {
		ff[ind] = i;
		f( ind + 1 );
	}
}

int main() {
	scanf( "%d%d" , &n , &m );
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ ) {
			scanf( "%d" , &ar[i][j] );
			ar[i][j] %= 3;
		}
	f( 0 );
	printf( "%d\n" , ans );
	return 0;
}
