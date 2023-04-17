#include <bits/stdc++.h>
#define  fi        first
#define  se	   	   second
#define  maxn	   100003
#define  pb		   push_back
using	 namespace std;
typedef  long long LL;
typedef  pair<int,int> pi;

int n,m,t,g;
int dt[maxn];
int ft[maxn];
int mark[maxn];
vector<int>adj[maxn];

void dfs( int node ) {
	printf( " %d" , node );
	dt[node] = ++t;
	mark[node] = g;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i];
		if( !mark[to] )
			dfs( to );
	}
	ft[node] = t;
}

int main() {
	scanf( "%d%d" , &n , &m );
	for( int i = 0 , x , y ; i < m ; i++ ) {
		scanf( "%d%d" , &x , &y );
		adj[x].pb( y );
		adj[y].pb( x );
	}
	for( int i = 1 ; i <= n ; i++ )
		if( !mark[i] ) {
			printf( "Group %d:" , ++g );
			dfs( i );
			puts( "" );
		}
	return 0;
}
