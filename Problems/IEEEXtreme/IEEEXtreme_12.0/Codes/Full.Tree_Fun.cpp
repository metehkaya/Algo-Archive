// Teammate : Osman Orhan Uysal

#include <bits/stdc++.h>
#define pb push_back
#define umax( x , y ) x = max( x , (y) )
using namespace std;

const int maxn = 1000020;

int a,b;
int T[maxn],val[maxn];
int dad[maxn][20],der[maxn];
vector<int> w[maxn];

void dfs( int n, int back, int s ) {
	der[n] = s;
	dad[n][0] = back;
	for( int i = 1 ; (1<<i) <= s ; i++ )
		dad[n][i] = dad[ dad[n][i-1] ][i-1];
	for( int i = 0 ; i < w[n].size() ; i++ )
		if( w[n][i] != back )
			dfs( w[n][i] , n , s+1 );
}

int lca( int x, int y ) {
	if( der[x] < der[y] )
		swap( x, y );
	for( int k = 20 ; k >= 0 ; k-- )
		if( (1<<k) <= der[x] && der[ dad[x][k] ] > der[y] )
			x = dad[x][k];
	if( der[x] != der[y] )
		x = dad[x][0];
	for( int k = 20 ; k >= 0 ; k-- )
		if( (1<<k) <= der[x] && dad[x][k] != dad[y][k] )
			x = dad[x][k], y = dad[y][k];
	if( x != y )
		x = dad[x][0];
	return x;
}

void dfs2(int n, int back) {
	for(int i=0;i<w[n].size();i++)
		if( w[n][i] != back ) {
			dfs2( w[n][i], n );
			T[n] += T[ w[n][i] ];
		}
	val[n] += T[n];
}

int main() {

	scanf("%d %d",&a,&b);
	for( int i = 1 , j , k ; i < a ; i++ ) {
		scanf("%d %d",&j,&k);
		j++, k++;
		w[j].pb( k );
		w[k].pb( j );
	}

	dfs( 1, 0, 0 );

	for(int i=1,j,k,t;i<=b;i++) {
		scanf("%d %d %d",&j,&k,&t); j++; k++;
		int l = lca( j, k );
		T[j] += t;
		T[k] += t;
		T[l] -= t+t;
		val[l] += t;
	}

	dfs2( 1, 0 );
	
	int maxi = 0;
	for( int i = 1 ; i <= a ; i++ )
		umax( maxi , val[i] );
	printf("%d\n",maxi);
	
	return 0;

}
