#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 10003
#define maxm 20003
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

int n,m,ans;
pii ar[maxn];
int tree[4*maxm];

set<int> myset;
map<int,int> myhash;

void update( int cx , int cy , int q , int val , int id ) {
	if( cy < q || q < cx )
		return;
	tree[id] = max( tree[id] , val );
	if( cx == cy )
		return;
	int mid = (cx + cy) >> 1;
	update( cx , mid , q , val , id * 2 );
	update( mid + 1 , cy , q , val , id * 2 + 1 );
}

int query( int cx , int cy , int qx , int qy , int id ) {
	if( cy < qx || qy < cx )
		return 0;
	if( qx <= cx && cy <= qy )
		return tree[id];
	int mid = (cx + cy) >> 1;
	int L = query( cx , mid , qx , qy , id * 2 );
	int R = query( mid + 1 , cy , qx , qy , id * 2 + 1 );
	return max( L , R );
}

int main() {
	scanf( "%d" , &n );
	for( int i = 0 ; i < n ; i++ ) {
		scanf( "%d%d%d" , &ar[i].fi.fi , &ar[i].fi.se , &ar[i].se );
		myset.insert( ar[i].fi.fi );
		myset.insert( ar[i].fi.se );
	}
	set<int>::iterator it = myset.begin();
	while( it != myset.end() ) {
		myhash[(*it)] = ++m;
		it++;
	}
	sort( ar , ar + n );
	for( int i = 0 ; i < n ; i++ ) {
		int x = myhash[ ar[i].fi.fi ];
		int y = myhash[ ar[i].fi.se ];
		int sum = query( 1 , m , 1 , x - 1 , 1 );
		sum += ar[i].se;
		ans = max( ans , sum );
		update( 1 , m , y , sum , 1 );
	}
	printf( "%d\n" , ans );
	return 0;
}