// Teammate : Osman Orhan Uysal

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long Lint;

const int maxn = 200020;
const Lint inf = 123456789LL * 123456789LL;
const Lint linf = 123456LL * 1234789LL;

int a,q,r,asd;
int par[maxn];
Lint divv[maxn], al[maxn];
Lint lo[maxn], hi[maxn];
Lint lod[maxn], hid[maxn];

string label[maxn];
string label_par[maxn];

map<string,int> mp;
vector<int> w[maxn];

int ch_al( int n ) {
	for( int i = 0 ; i < w[n].size() ; i++ )
		if( al[ w[n][i] ] == 0 )
			return 0;
	return 1;
}

void dfs( int n ) {

	for( int i = 0 ; i < w[n].size() ; i++ ) {
		int t = w[n][i];
		dfs( t );
	}

	if( w[n].size() == 0 ) {
		if( divv[n] )
			al[n] = divv[n];
		if( al[n] )
			divv[n] = al[n];
	}
	int ch2 = ch_al( n );

	if( ch2 && divv[n] ) {
		Lint h = divv[n];
		for( int i = 0 ; i < w[n].size() ; i++ )
			h += al[w[n][i]];
		if( al[n] )
			assert( al[n] == h );
		else
			al[n] = h;
	}

	if( ch2 && al[n] ) {
		Lint h = al[n];
		for( int i = 0 ; i < w[n].size() ; i++ )
			h -= al[w[n][i]];
		divv[n] = h;
	}

}

void dfs2( int n ) {
	if( w[n].size() == 0 ) {
		if( divv[n] )
			al[n] = divv[n];
		if( al[n] )
			divv[n] = al[n];
	}
	if( al[n] ) {
		int cnt = 0 , tt;
		Lint h = al[n];
		for( int i = 0 ; i < w[n].size() ; i++ ) {
			int t = w[n][i];
			if( !al[t] ) {
				cnt++;
				tt = t;
			} else h -= al[t];
		}
		if( cnt == 1 ) {
			if( divv[n] )
				al[tt] = h - divv[n];
		}
		if( cnt == 0 ) {
			if( !divv[n] )
				divv[n] = h;
			else
				assert( divv[n] == h );
		}
	}
	for( int i = 0 ; i < w[n].size() ; i++ ) {
		int t = w[n][i];
		dfs2( t );
	}
}

void dfs3( int n ) {
	lo[n] = 0;
	for( int i = 0 ; i < w[n].size() ; i++ ) {
		int t = w[n][i];
		dfs3( t );
		lo[n] += lo[t];
	}
	if( !divv[n] )
		lod[n] = 1;
	else
		lod[n] = divv[n];
	lo[n] += lod[n];
	if( al[n] && !(n==r && asd==1) )
		lo[n] = al[n];
}

void dfs4( int n, Lint u ) {

	hi[n] = u;
	if( al[n] ) {
		assert(u>=al[n]);
		hi[n] = al[n];
	}

	Lint tot = lod[n];
	for( int i = 0 ; i < w[n].size() ; i++ ) 
		tot += lo[ w[n][i] ];
	hid[n] = hi[n] - (tot - lod[n]);
	if( divv[n] )
		hid[n] = divv[n];

	for( int i = 0 ; i < w[n].size() ; i++ ) {
		int t = w[n][i];
		Lint h = tot - lo[ w[n][i] ];
		h = hi[n] - h;
		dfs4( t, h );
	}

}

int main() {

	scanf("%d %d",&a,&q);

	for( int i = 1 ; i <= a ; i++ ) {
		cin >> label[i];
		mp[label[i]] = i;
		cin >> label_par[i];
		scanf( "%lld %lld" , &divv[i] , &al[i] );
	}
	for( int i = 1 ; i <= a ; i++ ) {
		par[i] = mp[ label_par[i] ];
		if( !par[i] )
			r = i;
		else
			w[ par[i] ].pb( i );
	}

	dfs( r );
	dfs2( r );
	if( !al[r] )
		al[r] = 6e9 , asd = 1;
	dfs3( r );
	dfs4( r, inf );

	string s;

	for( int i = 1 ; i <= q ; i++ ) {
		cin >> s;
		int k = mp[s] , tp;
		cin >> tp;
		if( tp == 1 ) {
			assert( hid[k] );
			assert( lod[k] <= linf );
			printf("%lld %lld\n",lod[k],hid[k]);
		} else {
			assert( lo[k] );
			assert( hi[k] );
			assert( lo[k] <= linf );
			assert( hi[k] <= linf );
			printf("%lld %lld\n",lo[k],hi[k]);
		}
	}

	return 0;

}
