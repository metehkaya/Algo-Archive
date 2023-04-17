#include <bits/stdc++.h>
#define  fi        first
#define  se	   	   second
#define  maxn	   100003
#define  pb		   push_back
using	 namespace std;
typedef  long long LL;
typedef  pair<int,int> pi;

int n,m,s;
int dist[maxn];
vector<int>adj[maxn];

void bfs( int source ) {
	queue<int>Q;
	Q.push( source );
	memset( dist , -1 , sizeof(dist) );
	dist[source] = 0;
	while( !Q.empty() ) {
		int node = Q.front();
		Q.pop();
		for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
			int to = adj[node][i];
			if( dist[to] == -1 ) {
				Q.push( to );
				dist[to] = dist[node] + 1;
			}
		}
	}
}

int main() {
	scanf( "%d%d%d" , &n , &m , &s );
	for( int i = 0 , x , y ; i < m ; i++ ) {
		scanf( "%d%d" , &x , &y );
		adj[x].pb( y );
		adj[y].pb( x );
	}
	bfs( s );
	for( int i = 1 ; i <= n ; i++ ) {
		if( dist[i] == -1 )
			printf( "%d: No path from s\n" , i );
		else
			printf( "%d: %d\n" , i , dist[i] );
	}
	return 0;
}
