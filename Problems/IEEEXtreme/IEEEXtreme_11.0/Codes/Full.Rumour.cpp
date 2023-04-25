#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;

int T;
LL a,b;
vector<LL> v1,v2;

int main() {
	
	scanf( "%d" , &T );
	
	for( int tc = 0 ; tc < T ; tc++ ) {
		
		v1.clear();
		v2.clear();
		
		scanf( "%lld%lld" , &a , &b );
		if( a > b )
			swap( a , b );
		
		while( a != 1 ) {
			v1.pb( a );
			a /= 2;
		}
		v1.pb( a );
		
		while( b != 1 ) {
			v2.pb( b );
			b /= 2;
		}
		v2.pb( b );
		
		reverse( v1.begin() , v1.end() );
		reverse( v2.begin() , v2.end() );
		
		for( int i = 0 ; i < v1.size() ; i++ )
			if( i + 1 == v1.size() || v1[i+1] != v2[i+1] ) {
				printf( "%d\n" , v1.size() + v2.size() - 2 - 2 * i );
				break;
			}
		
	}

	return 0;
	
}
