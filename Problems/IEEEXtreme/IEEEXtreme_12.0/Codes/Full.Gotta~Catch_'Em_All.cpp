// Teammate : Osman Orhan Uysal

#include <bits/stdc++.h>
using namespace std;
typedef long long Lint;

const int maxn = 1020;

int a,b,L,T,sz;
int used[maxn];
int way[maxn][maxn];
bool ar[maxn][maxn];

bool dfs( int n ) {
	used[n] = 1;
	if(n == sz)
		return 1;
	for( int i = 1 ; i <= sz ; i++ )
		if( ar[n][i] && !used[i] && dfs( i ) ) {
			ar[n][i] = 0;
			ar[i][n] = 1;
			return 1;
		}
	return 0;
}

bool f( int n ) {
	memset( ar, 0, sizeof( ar ) );
	for( int i = 1 ; i <= a ; i++ )
		ar[0][i] = 1;
	for( int i = a+1 ; i <= a+b+b ; i++ )
		ar[i][sz] = 1;
	for( int i = 1 ; i <= a ; i++ )
		for( int j = 1 ; j <= b ; j++ ) {
			if( way[i][j] <= n )
				ar[i][a+j] = 1;
			if( way[i][j] <= n-T )
				ar[i][a+b+j] = 1;
		}
	int k = 0;
	memset( used, 0, sizeof( used ) );
	while( dfs( 0 ) ) {
		memset( used, 0, sizeof( used ) );
		k++;
		if( k >= L )
			return 1;
	}
	return k >= L;
}

void solve() {
	scanf("%d %d %d %d",&b,&a,&L,&T);
	sz = a+b+b+1;
	for( int i = 1 ; i <= a ; i++ )
		for( int j = 1 ; j <= b ; j++ )
			scanf("%d",&way[i][j]);
	int t = 0;
	for( int k = 20 ; k >= 0 ; k-- )
		if( !f( t+(1<<k) ) )
			t += 1<<k;
	t++;
	cout << t << endl;
}

int main() {
	int n = 1;
	scanf("%d",&n);
	while(n--)
		solve();
	return 0;
}
