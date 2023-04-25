#include <bits/stdc++.h>
#define maxn 1003
#define pb push_back
using namespace std;

int T,n,m;
int mark[maxn];
vector<int> adj[maxn];

void read() {
	scanf( "%d%d" , &n , &m );
	for( int i = 0 , x , y ; i < m ; i++ ) {
		scanf( "%d%d" , &x , &y );
		adj[x].pb( y );
		adj[y].pb( x );
	}
}

void reset() {
	memset( mark , 0 , sizeof(mark) );
	for( int i = 0 ; i < n ; i++ )
		adj[i].clear();
}

bool dfs( int node , int dad ) {
	mark[node] = 1;
	int dadCnt = 0;
	for( int i = 0 ; i < adj[node].size() ; i++ ) {
		if( adj[node][i] == dad )
			dadCnt++;
		else if( mark[adj[node][i]] == 1 )
			return true;
		else if( !mark[adj[node][i]] )
			if( dfs( adj[node][i] , node ) )
				return true;
	}
	mark[node] = 2;
	return (dadCnt >= 2);
}

bool solve() {
	for( int i = 0 ; i < n ; i++ )
		if( !mark[i] && dfs( i , -1 ) )
			return true;
	return false;
}

int main() {
	scanf( "%d" , &T );
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		read();
		printf( "%d\n" , solve() );
	}
	return 0;
}
