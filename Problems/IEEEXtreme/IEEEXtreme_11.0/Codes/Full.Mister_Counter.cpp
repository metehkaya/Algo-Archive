#include <bits/stdc++.h>
#define maxn 250003
using namespace std;

int n,m;
int L[maxn];
int R[maxn];
int ar[maxn];
int ord[maxn];

int main() {
	
	scanf( "%d" , &n );
	for( int i = 1 ; i <= n ; i++ )
		scanf( "%d" , &ar[i] );
	
	for( int i = 1 , j ; i <= n ; i = j + 1 ) {
		j = i;
		while( j < n && ar[j+1] < ar[j] )
			j++;
		for( int k = i ; k <= j ; k++ )
			L[k] = i , R[k] = j;
	}
	
	for( int i = 1 ; i <= n ; i++ ) {
		i = R[i];
		if( i == n )
			break;
		int l = i + 1;
		int r = R[i+1];
		ord[i] = 1;
		for( int k = r ; k >= l ; k-- ) {
			if( ar[i] > ar[k] )
				ord[i]++;
			else
				break;
		}
	}
	
	scanf( "%d" , &m );
	for( int i = 0 , l , r ; i < m ; i++ ) {
		scanf( "%d%d" , &l , &r );
		if( L[r] <= l ) {
			puts( "0" );
			continue;
		}
		int id = L[r] - 1;
		int length = r - id + 1;
		if( length % 2 ) {
			printf( "%d\n" , length );
			continue;
		}
		int rem = R[ L[r] ] - r;
		rem = max( 1 , ord[id] - rem );
		if( rem == length / 2 )
			printf( "%d\n" , length );
		else
			printf( "%d\n" , length - 1 );
	}
	
	return 0;

}
