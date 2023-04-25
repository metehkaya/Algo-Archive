#include <bits/stdc++.h>
#define maxp 105
#define maxs 1000005
using namespace std;

int n,m,q;
char s[maxs];
char p[maxp];
int last[26];
int nxt[maxs][26];

bool check( int bas ) {
	int curr = 0;
	for( int i = bas ; i <= m ; i++ ) {
		int val = p[i] - 'a';
		if( nxt[curr][val] == -1 )
			return false;
		curr = nxt[curr][val];
	}
	return true;
	
}

int main() {
	
	scanf( "%s" , s+1 );
	n = strlen( s + 1 );
	
	memset( last , -1 , sizeof( last ) );
	for( int id = n ; id >= 0 ; id-- ) {
		for( int i = 0 ; i < 26 ; i++ )
			nxt[id][i] = last[i];
		if( !id )
			continue;
		int val = s[id] - 'a';
		last[val] = id;
	}
	
	scanf( "%d" , &q );
	for( int tc = 0 ; tc < q ; tc++ ) {
		scanf( "%s" , p + 1 );
		m = strlen( p + 1 );
		int l = 1 , r = m , ans = 0;
		while( l <= r ) {
			int mid = ( l + r ) >> 1;
			if( check( mid ) )
				ans = m - mid + 1 , r = mid - 1;
			else
				l = mid + 1;
		}
		printf( "%d\n" , ans );
	}
	
	return 0;

}
