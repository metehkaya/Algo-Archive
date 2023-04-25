#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

int T,n;
int ar[maxn];
int tmp[2*maxn];

int main() {
	
	scanf( "%d" , &T );
	
	for( int tc = 1 ; tc <= T ; tc++ ) {
		
		scanf( "%d" , &n );
		for( int i = 1 ; i <= n ; i++ )
			scanf( "%d" , &ar[i] );
		
		sort( ar + 1 , ar + n + 1 );
		
		int lastzero = 0;
		while( lastzero < n && !ar[lastzero+1] )
			lastzero++;
		
		LL sum = 0;
		
		if( lastzero == n ) {
			puts( "0" );
			for( int i = 0 ; i < n ; i++ )
				printf( "0 " );
			puts( "" );
			continue;
		}
		
		int ind = lastzero + 1;
		
		if( ind == n - 1 ) {
			printf( "%lld\n" , (LL) ar[ind] * ar[ind+1] );
			for( int i = 0 ; i < lastzero ; i++ )
				printf( "0 " );
			printf( "%d %d\n" , ar[ind] , ar[ind+1] );
			continue;
		}
		
		if( ind == n ) {
			puts( "0" );
			for( int i = 0 ; i < lastzero ; i++ )
				printf( "0 " );
			printf( "%d\n" , ar[ind] );
			continue;
		}
		
		int l = n , r = n + 1;
		tmp[l] = ar[n-1] , tmp[r] = ar[n];
		
		for( int i = n - 2 ; i >= ind ; i -= 2 ) {
			if( i == ind ) {
				if( tmp[l] == tmp[r] )
					tmp[--l] = ar[i];
				else
					tmp[++r] = ar[i];
			}
			else {
				if( tmp[l] == tmp[r] && ar[i] == ar[i-1] && ar[ind] == ar[i] ) {
					tmp[--l] = ar[i];
					tmp[--l] = ar[i];
				}
				else {
					tmp[++r] = ar[i];
					tmp[--l] = ar[i-1];
				}
			}
		}
		
		int dir = 0;
		
		for( int i = 0 ; i <= r - l ; i++ ) {
			if( tmp[l+i] < tmp[r-i] ) {
				dir = -1;
				break;
			}
			else if( tmp[l+i] > tmp[r-i] ) {
				dir = 1;
				break;
			}
		}
		
		for( int i = l ; i < r ; i++ )
			sum += (LL) tmp[i] * tmp[i+1];
		
		printf( "%lld\n" , sum );
		
		for( int i = 0 ; i < lastzero ; i++ )
			printf( "0 " );
		
		if( dir == -1 )
			for( int i = l ; i <= r ; i++ )
				printf( "%d " , tmp[i] );
		else
			for( int i = r ; i >= l ; i-- )
				printf( "%d " , tmp[i] );
		
		puts( "" );
		
	}

	return 0;
	
}
