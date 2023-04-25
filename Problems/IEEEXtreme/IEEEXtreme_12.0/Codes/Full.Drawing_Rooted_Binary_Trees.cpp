// Teammate : Osman Orhan Uysal

#include <bits/stdc++.h>
#define pb push_back
#define umax( x , y ) x = max( x , (y) )
using namespace std;

const int maxn = 2020;

int a;
int pos[maxn];
char pri[maxn];
int L[maxn],R[maxn];
char ar[maxn],bs[maxn];

vector<int> ans[maxn];

int f( int a, int x ) {
	int l = L[a];
	int r = R[a];
	return l <= x && x <= r;
}

int main() {

	while( scanf(" %s",ar+1) != EOF ) {

		memset( L, 0, sizeof( L ) );
		memset( R, 0, sizeof( R ) );
		memset( pos, 0, sizeof( pos ) );
		scanf(" %s",bs+1);

		a = strlen( ar+1 );
		ans[0].clear();
		for( int i = 1 ; i <= a ; i++ ) {
			ans[i].clear();
			ar[i] -= 'a';
			bs[i] -= 'a';
			pos[ ar[i] ] = i;
		}

		vector<int> v;
		int maxi = 0;

		for( int i = 1 ; i <= a ; i++ ) {
			int k = pos[ bs[i] ];
			while( v.size() > 1 && !f( v[v.size()-1], k ) )
				v.pop_back();
			ans[v.size()].pb( k );
			if( i == 1 ) {
				L[k] = 1;
				R[k] = a;
			} else {
				int h = v[v.size()-1];
				L[k] = L[h];
				R[k] = R[h];
				if( k < h ) R[k] = h;
				else L[k] = h;
			}
			v.pb( k );
			umax( maxi, (int)v.size() );
		}

		for( int i = 0 ; i < maxi ; i++ ) {
			for( int j = 0 ; j <= a ; j++ )
				pri[j] = ' ';
			for( int j = 0 ; j < ans[i].size() ; j++ ) {
				int k = ans[i][j];
				pri[k] = 'a' + ar[k];
			}
			for( int j = 1 ; j <= a ; j++ )
				printf("%c",pri[j]); printf("\n");
		}
	}

	return 0;

}
