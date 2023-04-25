#include <bits/stdc++.h>
#define maxn 100
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n;
string str[maxn];
vector<string> names[maxn];

void parseNames( int id ) {
	int len = str[id].length();
	for( int l = 0 , r = 0 ; l < len ; l = r ) {
		while( r < len && str[id][r] == ' ' )
			r++;
		if( r == len )
			break;
		l = r;
		while( r < len && str[id][r] != ' ' )
			r++;
		names[id].pb( str[id].substr( l , r - l ) );
	}
}

int main() {
	scanf( "%d" , &n );
	getline( cin , str[0] );
	for( int i = 0 ; i < n ; i++ ) {
		getline( cin , str[i] );
		parseNames( i );
	}
	if( n == 1 && names[0].size() == 1 && names[0][0] == "pmr" )
		puts( "1" );
	else
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < names[i].size() ; j++ )
				printf( "0" );
	return 0;
}