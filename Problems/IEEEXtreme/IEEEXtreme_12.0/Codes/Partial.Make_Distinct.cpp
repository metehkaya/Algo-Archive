// Teammate : Osman Orhan Uysal

#include <bits/stdc++.h>
#define umin( x , y ) x = min( x , (y) )
using namespace std;
typedef long long Lint;

const int maxn = 200020;

int a;
int ar[maxn];

Lint get( int x, int b, int s ) {
	Lint ans = 0;
	for( int i = b ; i <= s ; i++ )
		ans += abs(x+i-1-ar[i]);
	return ans;
}

int get2( int x, int b, int s ) {
	int ans = 0;
	for( int i = b ; i <= s ; i++ )
		ans += (ar[i] >= (x+i));
	return ans;
}

Lint solve( int b, int s ) {
	int h = (b+s)/2;
	int l = -a, r = a;
	while( l+1 < r ) {
	    int m = (l+r)/2;
	    if( get2( m, b, s ) > h ) l = m;
	    else r = m;
	}
	Lint ans = 1e18;
	for( int i = -5 ; i <= 5 ; i++ )
		umin( ans, get( l+i, b, s ) );
	return ans;
}

struct node {
	int b, s, lo, hi;
	node( int _a=0, int _b=0, int _c=0, int _d=0 ) {
		b = _a;
		s = _b;
		lo = _c;
		hi = _d;
	}
};

int at;
int dn[2020][2020], dummy = 1005;
node st[maxn];

int f( int n, int last ) {
	if( n == a+1 )
		return 0;
	int &ret = dn[n][last+dummy];
	if( ret != -1 )
		return ret;
	ret = 1e9;
	for( int i = last+1 ; i <= a+a ; i++ )
		umin( ret , abs(ar[n]-i) + f(n+1,i) );
	return ret;
}

int main() {

	scanf("%d",&a);

	Lint sum = 0;
	for( int i = 1 ; i <= a ; i++ ) {
		scanf("%d",&ar[i]);
		sum += ar[i];
	}
	sort( ar+1 , ar+1+a );

	if( a <= 1000 ) {
	    memset( dn, -1, sizeof( dn ) );
	    cout << f( 1, -a ) << endl;
	    return 0;
	}

	at = 0;

	for( int i = 1 ; i <= a ; ) {

		int j = i;
		while( j <= a && ar[j] == ar[i] )
			j++;
		int bb = ar[j] - (j-i)/2;
		node t = node( i, j-1, bb, bb+j-i-1 );

		while( at > 0 && st[at].hi >= t.lo ) {
			int sz = (st[at].hi-st[at].lo+1) + t.hi-t.lo+1;
			int beg = t.lo - (st[at].hi-st[at].lo)/2;
			t = node( st[at].b, t.s, beg, beg+sz-1 );
			at--;
		}

		st[++at] = t;
		i = j;

	}

	Lint ans = 0;
	for( int i = 1 ; i <= at ; i++ )
		ans += solve( st[i].b, st[i].s );
	printf("%lld\n",ans);

	return 0;

}
