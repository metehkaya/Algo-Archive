#include <bits/stdc++.h>
#define  fi        first
#define  se	   	   second
#define  maxn	   100003
#define  pb		   push_back
using	 namespace std;
typedef  long long LL;
typedef  pair<int,int> pi;

struct data {
	int to,len;
};

bool operator<( const data &a , const data &b ) {
	return a.len > b.len;
}

data getData( int _to , int _len ) {
	data d;
	d.to = _to;
	d.len = _len;
	return d;
}

int n,m,s;
int dist[maxn];
bool mark[maxn];
vector<pi>adj[maxn];
priority_queue<data>heap;

int main() {
	scanf( "%d%d%d" , &n , &m , &s );
	for( int i = 0 , x , y , z ; i < m ; i++ ) {
		scanf( "%d%d%d" , &x , &y , &z );
		adj[x].pb( pi( y , z ) );
		adj[y].pb( pi( x , z ) );
	}
	heap.push( getData( s , 0 ) );
	while( !heap.empty() ) {
		data tmp = heap.top();
		heap.pop();
		int node = tmp.to;
		int length = tmp.len;
		if( mark[node] )
			continue;
		mark[node] = true;
		dist[node] = length;
		for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
			int to = adj[node][i].fi;
			int len = adj[node][i].se;
			if( !mark[to] )
				heap.push( data( getData( to , length + len ) ) );
		}
	}
	for( int i = 1 ; i <= n ; i++ ) {
		if( !mark[i] )
			printf( "%d: No path from s\n" , i );
		else
			printf( "%d: %d\n" , i , dist[i] );
	}
	return 0;
}
