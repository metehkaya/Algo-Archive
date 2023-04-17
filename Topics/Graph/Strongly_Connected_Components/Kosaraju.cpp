#include <bits/stdc++.h>
#define  fi        first
#define  se	   	   second
#define  maxn	   100003
#define  pb		   push_back
using	 namespace std;
typedef  long long LL;
typedef  pair<int,int> pi;

int n,m,t,g;
int st[maxn];
int mark[maxn];
vector<int>adj[maxn];
vector<int>adjT[maxn];

void dfs2( int node ) {
	printf( " %d" , node );
	mark[node] = 2;
	for( int i = 0 ; i < (int) adjT[node].size() ; i++ ) {
		int to = adjT[node][i];
		if( mark[to] == 1 )
			dfs2( to );
	}
}

void dfs1( int node ) {
	mark[node] = 1;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i];
		if( !mark[to] )
			dfs1( to );
	}
	st[++t] = node;
}

int main() {
	scanf( "%d%d" , &n , &m );
	for( int i = 0 , x , y ; i < m ; i++ ) {
		scanf( "%d%d" , &x , &y );
		adj[x].pb( y );
		adjT[y].pb( x );
	}
	for( int i = 1 ; i <= n ; i++ )
		if( !mark[i] )
			dfs1( i );
	for( int i = n ; i >= 1 ; i-- ) {
		int node = st[i];
		if( mark[node] == 1 ) {
			printf( "Group %d:" , ++g );
			dfs2( node );
			puts( "" );
		}
	}
	return 0;
}
