#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;
typedef vector<int> vi;
typedef pair<vi,vi> pvi;

int n,m,k;
vector<pvi> w;
set<pii> myset;
vector<pi> v[59049];

void read1() {
	string str;
	cin >> str;
	int len = str.length() , i = 0;
	while( str[i] != ',' ) {
		n *= 10;
		n += str[i++] - '0';
	}
	i++;
	while( i < len ) {
		m *= 10;
		m += str[i++] - '0';
	}
	k = 1;
	for( int i = 0 ; i < m ; i++ )
		k *= 3;
}

void read2() {
	string str;
	for( int l = 0 ; l < m ; l++ ) {
		cin >> str;
		int len = str.length();
		int i = 0;
		vi v1,v2;
		while( str[i] != '-' ) {
			int val = str[i++] - 'A';
			v1.pb( val );
		}
		i++;
		while( i < len ) {
			int val = str[i++] - 'A';
			v2.pb( val );
		}
		w.pb( pvi( v1 , v2 ) );
	}
}

int main() {
	read1();
	read2();
	for( int i = 0 ; i < n ; i++ )
		for( int j = i + 1 ; j < n ; j++ ) {
			int val = 0;
			for( int l = 0 ; l < m ; l++ ) {
				int cnt0 = 0 , cnt1 = 0;
				for( int o = 0 ; o < w[l].fi.size() ; o++ )
					if( i == w[l].fi[o] || j == w[l].fi[o] )
						cnt0++;
				for( int o = 0 ; o < w[l].se.size() ; o++ )
					if( i == w[l].se[o] || j == w[l].se[o] )
						cnt1++;
				val *= 3;
				if( cnt0 < cnt1 )
					val += 0;
				else if( cnt0 == cnt1 )
					val += 1;
				else
					val += 2;
			}
			v[val].pb( pi( i , j ) );
		}
	for( int s = 0 ; s < k ; s++ )
		for( int i = 0 ; i < v[s].size() ; i++ )
			for( int j = i + 1 ; j < v[s].size() ; j++ )
				myset.insert( pii( v[s][i] , v[s][j] ) );
	set<pii>::iterator it = myset.begin();
	while( it != myset.end() ) {
		printf( "%c%c=%c%c\n" , (*it).fi.fi + 'A' , (*it).fi.se + 'A' , (*it).se.fi + 'A' , (*it).se.se + 'A' );
		it++;
	}
	return 0;
}