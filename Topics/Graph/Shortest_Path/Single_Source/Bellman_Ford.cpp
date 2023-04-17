#include <bits/stdc++.h>
#define  maxn	   503
#define  inf	   (1<<29)
#define  fi        first
#define  se	   	   second
#define  pb		   push_back
using	 namespace std;
typedef  long long LL;
typedef  pair<int,int> pi;
typedef  pair<pi,int> pii;

int n,m,s;
int dist[maxn];
vector<pii>E;

int main() {
	scanf( "%d%d%d" , &n , &m , &s );
	for( int i = 0 , x , y , z ; i < m ; i++ ) {
		scanf( "%d%d%d" , &x , &y , &z );
		E.pb( pii( pi( x , y ) , z ) );
	}
	for( int i = 1 ; i <= n ; i++ )
		if( i != s )
			dist[i] = inf;
	for( int t = 1 , x , y , z ; t < n ; t++ )
		for( int i = 0 ; i < m ; i++ ) {
			x = E[i].fi.fi , y = E[i].fi.se , z = E[i].se;
			dist[y] = min( dist[y] , dist[x] + z );
		}
	bool neg_cycle = false;
	for( int i = 0 , x , y , z ; i < m && !neg_cycle ; i++ ) {
		x = E[i].fi.fi , y = E[i].fi.se , z = E[i].se;
		if( dist[y] > dist[x] + z )
			neg_cycle = true;
	}
	if( neg_cycle )
		puts( "There is a negative cycle in the given graph." );
	else
		puts( "There is no negative cycle in the given graph." );
	return 0;
}
