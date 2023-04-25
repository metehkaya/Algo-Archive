#include <bits/stdc++.h>
#define maxk 8
#define maxn 205
#define pb push_back
using namespace std;

int n,t;
int dt[maxn];
int ft[maxn];
int ST[maxn];
int mark[maxn];
bool cycle[maxn];
int par[maxn][maxk];
bool mat[maxn][maxn];

vector<int> adj[maxn];
vector<int> add[maxn];

void processLine( int root , string line ) {
	
	int sz = line.size();
	for( int i = 0 ; i < n ; i++ )
		if( root != i )
			mat[root][i] = true;
	
	for( int l = 0 , r ; l < sz ; l = r + 1 ) {
		r = l;
		int number = 0;
		while( r < sz && line[r] != ' ' ) {
			number *= 10;
			number += line[r++] - '0';
		}
		mat[root][number] = false;
	}
	
}

int lca( int u , int v ) {
	if( dt[u] <= dt[v] && ft[v] <= ft[u] )
		return u;
	if( dt[v] <= dt[u] && ft[u] <= ft[v] )
		return v;
	int node = u , LCA = 0;
	for( int i = maxk - 1 ; i >= 0 ; i-- ) {
		int tmp = par[node][i];
		if( !tmp )
			continue;
		if( dt[tmp] <= dt[v] && ft[v] <= ft[tmp] )
			LCA = tmp;
		else
			node = tmp;
	}
	return LCA;
}

void update( int id , int val ) {
	while( id <= n ) {
		ST[id] += val;
		id += ( id & (-id) );
	}
}

int query( int id ) {
	int sum = 0;
	while( id ) {
		sum += ST[id];
		id -= ( id & (-id) );
	}
	return sum;
}

void dfs3( int node ) {
	
	mark[node] = 2;
	
	for( int i = 0 ; i < add[node].size() ; i++ )
		update( dt[ add[node][i] ] , +1 );
	
	if( query( ft[node] ) - query( dt[node] - 1 ) )
		cycle[node] = true;
	
	for( int i = 0 ; i < adj[node].size() ; i++ )
		if( mark[ adj[node][i] ] != 2 )
			dfs3( adj[node][i] );
	
	for( int i = 0 ; i < add[node].size() ; i++ )
		update( dt[ add[node][i] ] , -1 );
	
}

void dfs2( int node ) {
	
	mark[node] = 1;
	
	for( int i = 0 ; i < adj[node].size() ; i++ ) {
		int u = adj[node][i];
		if( mark[u] != 1 )
			dfs2( adj[node][i] );
		else {
			if( ft[u] < dt[node] ) {
				ft[node] = t;
				int LCA = lca( node , u );
				add[LCA].pb( u );	
				add[LCA].pb( node );
			}
			else if( dt[u] <= dt[node] && ft[node] <= ft[u] )
				add[u].pb( node );
		}
	}
	
}

void dfs1( int node , int dad ) {
	
	dt[node] = ++t;
	
	par[node][0] = dad;
	for( int i = 1 ; i < maxk ; i++ )
		par[node][i] = par[ par[node][i-1] ][i-1];
	
	for( int i = 0 ; i < adj[node].size() ; i++ ) {
		int u = adj[node][i];
		if( !dt[u] )
			dfs1( adj[node][i] , node );
	}
	
	ft[node] = t;
	
}

int main() {
	
	scanf( "%d\n" , &n );
	for( int i = 0 ; i < n ; i++ ) {
		string line;
		getline( cin , line );
		processLine( i , line );
	}
	
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < n ; j++ )
			if( mat[i][j] )
				adj[i].pb( j );
	
	for( int i = 0 ; i < n ; i++ )
		if( !dt[i] )
			dfs1( i , 0 );
	
	for( int i = 0 ; i < n ; i++ )
		if( mark[i] != 1 )
			dfs2( i );
	
	for( int i = 0 ; i < n ; i++ )
		if( mark[i] != 2 )
			dfs3( i );
	
	int ans = 0;
	for( int i = 0 ; i < n ; i++ )
		if( !cycle[i] )
			ans++;
	
	printf( "%d\n" , ans );
	
	return 0;

}
