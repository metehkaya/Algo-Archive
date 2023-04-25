#include <bits/stdc++.h>
#define maxk 17
#define maxn 100003
#define pb push_back
using namespace std;
typedef long long LL;

int n,m,t;
int dt[maxn];
int ft[maxn];
int dad[maxn];
int lvl[maxn];
int ST[4*maxn];
bool cycle[maxn];
int par[maxn][maxk];

vector<int> add[maxn];
vector<int> tree[maxn];
vector<int> nontree[maxn];

int find( int u ) {
	if( u == dad[u] )
		return u;
	return dad[u] = find( dad[u] );
}

void merge( int u , int v ) {
	if( lvl[u] >= lvl[v] ) {
		dad[v] = u;
		lvl[u] = max( lvl[u] , lvl[v] + 1 );
	}
	else
		dad[u] = v;
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

void dfs3( int node , int dad ) {
	
	for( int i = 0 ; i < add[node].size() ; i++ )
		update( dt[ add[node][i] ] , +1 );
	
	if( query( ft[node] ) - query( dt[node] - 1 ) )
		cycle[node] = true;
	
	for( int i = 0 ; i < tree[node].size() ; i++ )
		if( tree[node][i] != dad )
			dfs3( tree[node][i] , node );
	
	for( int i = 0 ; i < add[node].size() ; i++ )
		update( dt[ add[node][i] ] , -1 );
	
}

void dfs2( int node , int dad ) {
	
	for( int i = 0 ; i < tree[node].size() ; i++ )
		if( tree[node][i] != dad )
			dfs2( tree[node][i] , node );
	
	for( int i = 0 ; i < nontree[node].size() ; i++ ) {
		int u = nontree[node][i];
		if( dt[node] <= dt[u] && ft[u] <= ft[node] )
			continue;
		if( dt[node] > ft[u] )
			continue;
		if( dt[u] <= dt[node] && ft[node] <= ft[u] )
			add[u].pb( node );
		else {
			int LCA = lca( node , u );
			add[LCA].pb( u );
			add[LCA].pb( node );
		}
	}
	
}

void dfs1( int node , int dad ) {
	
	dt[node] = ++t;
	
	par[node][0] = dad;
	for( int i = 1 ; i < maxk ; i++ )
		par[node][i] = par[ par[node][i-1] ][i-1];
	
	for( int i = 0 ; i < tree[node].size() ; i++ )
		if( tree[node][i] != dad )
			dfs1( tree[node][i] , node );
	
	ft[node] = t;
	
}

int main() {
	
	scanf( "%d%d" , &n , &m );
	
	for( int i = 1 ; i <= n ; i++ )
		lvl[i] = 0 , dad[i] = i;
	
	for( int i = 0 , x , y ; i < m ; i++ ) {
		
		scanf( "%d%d" , &x , &y );
		
		int u = x , v = y;
		
		u = find( u );
		v = find( v );
		
		if( u != v ) {
			merge( u , v );
			tree[x].pb( y );
			tree[y].pb( x );
		}
		else {
			nontree[x].pb( y );
			nontree[y].pb( x );
		}
		
	}
	
	for( int i = 1 ; i <= n ; i++ )
		if( find(i) == i )
			dfs1( i , 0 );
	
	for( int i = 1 ; i <= n ; i++ )
		if( find(i) == i )
			dfs2( i , 0 );
	
	for( int i = 1 ; i <= n ; i++ )
		if( find(i) == i )
			dfs3( i , 0 );
	
	for( int i = 1 ; i <= n ; i++ )
		if( !cycle[i] )
			printf( "%d\n" , i );
	
	return 0;

}
