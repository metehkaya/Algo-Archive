#include <bits/stdc++.h>
#define  fi        first
#define  se	   	   second
#define  maxn	   100003
#define  pb		   push_back
using	 namespace std;
typedef  long long LL;
typedef  pair<int,int> pi;
typedef  pair<pi,int> pii;

bool comp( pii a , pii b ) {
	return a.se < b.se;
}

int n,m,sum;
int par[maxn];
int lvl[maxn];
vector<pii>E;
vector<int>mst;

int find( int node ) {
	if( node == par[node] )
		return node;
	return par[node] = find( par[node] );
}

void merge( int x , int y ) {
	if( lvl[x] < lvl[y] )
		par[x] = y;
	else if( lvl[y] < lvl[x] )
		par[y] = x;
	else {
		par[x] = y;
		lvl[y]++;
	}
}

void kruskal() {
	for( int i = 1 ; i <= n ; i++ )
		par[i] = i;
	sort( E.begin() , E.end() , comp );
	for( int i = 0 , x , y , z ; i < m && mst.size() < n-1 ; i++ ) {
		x = E[i].fi.fi , y = E[i].fi.se , z = E[i].se;
		x = find(x);
		y = find(y);
		if( x != y ) {
			sum += z;
			mst.pb( i );
			merge( x , y );
		}
	}
}

int main() {
	scanf( "%d%d" , &n , &m );
	for( int i = 0 , x , y , z ; i < m ; i++ ) {
		scanf( "%d%d%d" , &x , &y , &z );
		E.pb( pii( pi( x , y ) , z ) );
	}
	kruskal();
	if( mst.size() < n-1 )
		puts( "There is no MST - Given graph is not connected" );
	else {
		printf( "Total weight: %d\n" , sum );
		for( int i = 0 ; i < mst.size() ; i++ ) {
			int e = mst[i];
			printf( "%d %d %d\n" , E[e].fi.fi , E[e].fi.se , E[e].se );
		}
	}
	return 0;
}
