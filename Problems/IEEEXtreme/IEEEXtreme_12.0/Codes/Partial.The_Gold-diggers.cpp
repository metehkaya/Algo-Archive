// Teammate : Osman Orhan Uysal

#include <bits/stdc++.h>
#define pb push_back
#define umax( x , y ) x = max( x , (y) )
using namespace std;

const int maxn = 200020;

int a;
int dn[30][30][150];

string s;
vector<int> v[maxn],rev[maxn];

int ct( int mas ) {
	int ret = 0;
	for( int i = 0 ; i < 7 ; i++ )
		if( (1<<i) & mas )
			ret++;
	return ret;
}

int f( int x, int y, int mask ) {

	if( mask == 0 )
		return 0;
	
	int &ret = dn[x][y][mask];
	if( ret != -1 )
		return ret;
	
	ret = 0;
	for( int i = 0 ; i < v[x].size() ; i++ ) {
		int t = v[x][i];
		if( t <= x ) continue;
		int mask2 = mask;
		if( t >= a-7 )
			if( mask2 & (1<<(a-t-1)) ) {
				mask2^=1<<(a-t-1);
				int l = ct( mask2 );
				umax( ret, 1+l-f( y, t, mask2 ) );
			}
		int l = ct( mask2 );
		umax( ret, l-f( y, t, mask2 ) );
	}

	return ret;

}

struct node {
	int x, y, mask;
	int mal;
	friend bool operator < ( const node &a, const node &b ) { 
		if( a.mal == b.mal ) return a.y < b.y;
		return a.mal < b.mal;
	}
	node( int _x=0, int _y=0, int _mask=0, int _mal=0 ) {
		x=_x, y=_y, mal=_mal, mask=_mask;
	}
};

void bfs() {

	priority_queue<node> q;
	for( int i = 0 ; i < a ; i++ )
		for( int j = 0 ; j < a ; j++ )
			q.push( node( i, j, (1<<7)-1, 0 ) );

	while( !q.empty() ) {

		int x = q.top().x;
		int y = q.top().y;
		int mask = q.top().mask;
		int mal = q.top().mal; q.pop();
		int &H = dn[x][y][mask];

		if( mal <= H )
			continue;
		H = mal;

		int l = ct( mask );
		if( y >= a-7 && !((1<<(a-y-1))&mask) )
			for( int i = 0 ; i < rev[y].size() ; i++ ) {
				int t = rev[y][i];
				int mask2 = mask | (1<<(a-y-1));
				q.push( node( rev[y][i], x, mask2, 1+l-mal ) );
			}
		else
			for( int i = 0 ; i < rev[y].size() ; i++ )
				q.push( node( rev[y][i], x, mask, l-mal ) );
		
	}

}

int main() {

	memset( dn, -1, sizeof( dn ) );

	scanf("%d",&a);
	getline( cin, s );
	for( int i = 0 ; i < a ; i++ ) {
		getline( cin, s );
		for( int j = 0 , h = 0 ; j < s.size() ; j++ ) {
			if( s[j] != ' ' ) h = h*10 + s[j] - '0';
			if( s[j] == ' ' || j == s.size()-1 ) {
				v[i].pb( h );
				rev[h].pb( i );
				h = 0;
			}
		}
	}
	
	cout << f( 0, 0, (1<<7)-1 ) << endl;
	
	return 0;

}
