// Teammate : Osman Orhan Uysal

#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define umin( x , y ) x = min( x , (y) )
using namespace std;
typedef long long Lint;
typedef pair<int,int> ii;

int b;
Lint a;
vector<ii> v;

Lint f( Lint n ) {
	Lint ret = 1e18;
	for( int i = 0 ; i < v.size() ; i++ ) {
		int h = v[i].fi;
		Lint c = h;
		Lint t = 0;
		while( c <= n ) {
			t += n / c;
			c *= h;
		}
		umin( ret, t/v[i].se );
	}
	return ret;
}

void solve() {
	v.clear();
	scanf("%d %lld",&b,&a);
	for( int i = 2 ; i <= b ; i++ )
		if( b % i == 0 ) {
			int h = 0;
			while( b % i == 0 )
				b /= i, h++;
			v.pb( ii( i, h ) );
		}
	if( b != 1 )
		v.pb( ii( b, 1 ) );
	Lint t = 0;
	for( Lint k = 55 ; k >= 0 ; k-- )
		if( f( t+(1ll<<k) ) < a )
			t += (1ll<<k);
	t++;
	if( f( t ) != a )
		cout << "-1" << endl;
	else
		cout << t << endl;
}

int main() {
	int n = 1;
	scanf("%d",&n);
	while(n--)
		solve();
	return 0;
}
