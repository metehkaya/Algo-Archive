// Teammate : Osman Orhan Uysal

#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin() , x.end()
#define umax( x , y ) x = max( x , (y) )
using namespace std;
typedef long long Lint;
typedef pair<int,int> ii;

const int maxn = 1000020;

int N,sz,a,cnt,maxi,at;

int st[maxn];
int en[maxn];
int beg[maxn];
int der[maxn];
char ar[maxn];

Lint ans;
Lint num[maxn];

vector<ii> w[maxn];
vector<int> v[maxn];
vector<Lint> S[maxn];

bool comp( const ii &a, const ii &b ) {
	return a.se > b.se;
}

int dfs( int n, int s ) {
	beg[n] = ++cnt;
	num[s] += w[n].size() + 1;
	v[s].pb( beg[n] );
	S[s].pb( w[n].size() + 1 );
	if( S[s].size() > 1 )
		S[s][ S[s].size()-1 ] += S[s][ S[s].size()-2 ];
	der[n] = s;
	int ret = 0;
	for( int i = 0 ; i < w[n].size() ; i++ ) {
		int t = w[n][i].se = dfs( w[n][i].fi, s + 1 );
		umax( ret, t );
	}
	sort( all( w[n] ), comp );
	if( w[n].size() > 1 )
		umax( maxi, w[n][0].se + w[n][1].se + s );
	if( w[n].size() > 0 )
		umax( maxi, w[n][0].se + s );
	sort( all( w[n] ) );
	ret++;
	en[n] = cnt;
	return ret;
}

void dfs2( int n ) {
	for( int i = 0 ; i < w[n].size() ; i++ )
		dfs2( w[n][i].fi );
	for( int i = 0 ; i < w[n].size() ; i++ ) {
		int mm = w[n][i].se;
		for( int j = i ; j < w[n].size() ; j++ ) {
			umax( mm, w[n][j].se );
			int h = maxi - mm;
			int e = upper_bound( all( v[h] ), en[ w[n][j].fi ] ) - v[h].begin() - 1;
			int b = lower_bound( all( v[h] ), beg[ w[n][i].fi ] ) - v[h].begin() - 1;
			Lint v1 = (e >= 0) ? S[h][e]:0;
			Lint v2 = (b >= 0) ? S[h][b]:0;
			if( der[n] == h )
				v1++;
			ans += num[ h ] - (v1 - v2);
		}
	}

}

int main() {
	scanf(" %s",ar+1);
	sz = strlen( ar+1 );
	assert( ar[1] == '(' );
	st[++at] = 0;
	for( int i = 1 ; i <= sz ; i++ ) {
		if( ar[i] == '(' ) {
			N++;
			if( at > 0 )
				w[st[at]].pb( ii( N, 0 ) );
			st[++at] = N;
		}
		else {
			at--;
			assert( at >= 1 );
		}
	}
	dfs( 0 , 0 );
	dfs2( 0 );
	cout << ans << endl;
	return 0;
}
