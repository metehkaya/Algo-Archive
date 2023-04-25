#include <bits/stdc++.h>
using namespace std;

int n;
double r;
char let[3];
double deg[26];

string str;

int main() {
	
	scanf( "%lf" , &r );
	for( int i = 0 ; i < 26 ; i++ ) {
		scanf( "%s" , let );
		scanf( "%lf\n" , &deg[ let[0] - 'A' ] );
	}
	getline( cin , str );
	
	int last = -1;
	double cost = 0;
	n = str.size();
	
	for( int i = 0 ; i < n ; i++ ) {
		
		if( str[i] >= 'a' && str[i] <= 'z' )
			str[i] -= 'a' - 'A';
		if( str[i] < 'A' || str[i] > 'Z' ) {
			// last = -1;
			continue;
		}
		if( last == -1 ) {
			last = str[i] - 'A';
			continue;
		}
		
		double a = deg[last];
		double b = deg[ str[i] - 'A' ];
		if( a > b )
			swap( a , b );
		
		double diff = min( b - a , 360 + a - b );
		double rad = M_PI * diff / 180;
		
		double length = sqrt( 2 * r * r * ( 1 - cos(rad) ) );
		cost += length;
		
		last = str[i] - 'A';
		
	}
	
	if( last != -1 )
		cost += r;
	
	int ans;
	
	if( cost > (int)cost + 1e-8 )
		ans = (int)(cost) + 1;
	else
		ans = (int)(cost);
	
	printf( "%d\n" , ans );
	
	return 0;

}
