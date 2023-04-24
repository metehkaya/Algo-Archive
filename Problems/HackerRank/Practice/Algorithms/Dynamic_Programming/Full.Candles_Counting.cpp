#include <bits/stdc++.h>
#define fi first
#define se second
#define maxb 128
#define maxn 50001
#define mod 1000000007
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n,k,b;
int tree[maxb][maxn];

int query( int id , int q ) {
	int res = 0;
	while( q ) {
		res = ( tree[id][q] + res ) % mod,
		q -= ( q & (-q) );
	}
	return res;
}

void update( int id , int q , int val ) {
	while( q < maxn ) {
		tree[id][q] = ( tree[id][q] + val ) % mod,
		q += ( q & (-q) );
	}
}

int main() {
	scanf("%d%d",&n,&k);
	b = (1<<k);
	for( int i = 1 , h , c ; i <= n ; i++ ) {
		scanf("%d%d",&h,&c);
		c--;
		vector<pi> v;
		v.pb( pi(0,1) );
		for( int j = 1 ; j < b ; j++ )
			v.pb( pi( j , query( j , h-1 ) ) );
		for( int j = 0 , id , val ; j < b ; j++ ) {
			id = v[j].fi;
			val = v[j].se;
			update( (id|(1<<c)) , h , val );
		}
	}
	printf("%d\n",query( b-1 , maxn-1 ));
	return 0;
}
