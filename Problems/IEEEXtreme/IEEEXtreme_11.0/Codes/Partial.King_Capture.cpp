#include <bits/stdc++.h>
#define maxn 101
#define pb push_back
using namespace std;

int n,m;
int dist[maxn][maxn];
vector<int> adj[maxn];

void goo( int player , int opponent ) {
	
	if( player == opponent )
		return;
	
	vector<int>v;
	int cdist = dist[player][opponent];
	
	for( int i = 0 ; i < adj[player].size() ; i++ ) {
		int to = adj[player][i];
		if( dist[to][opponent] < cdist )
			v.pb( to );
	}
	
	int sz = v.size();
	int ind = rand() % sz;
	int nextPlayer = v[ind];
	
	cout << nextPlayer << endl;
	cout.flush();
	
	if( nextPlayer == opponent )
		return;
	
	scanf( "%d" , &opponent );
	goo( nextPlayer , opponent );
	
}

int main() {
	
	srand( time(NULL) );
	
	scanf( "%d%d" , &n , &m );
	
	for( int i = 1 ; i < n ; i++ )
		for( int j = i + 1 ; j <= n ; j++ )
			dist[i][j] = dist[j][i] = maxn;
	
	for( int i = 1 , x , y ; i <= m ; i++ ) {
		scanf( "%d%d" , &x , &y );
		adj[x].pb( y );
		adj[y].pb( x );
		dist[x][y] = dist[y][x] = 1;
	}
	
	for( int k = 1 ; k <= n ; k++ )
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 1 ; j <= n ; j++ )
				dist[i][j] = min( dist[i][j] , dist[i][k] + dist[k][j] );
	
	int player = -1 , best = maxn;
	for( int i = 1 ; i <= n ; i++ ) {
		int mx = 0;
		for( int j = 1 ; j <= n ; j++ )
			mx = max( mx , dist[i][j] );
		if( mx < best ) {
			best = mx;
			player = i;
		}
	}
	
	cout << player << endl;
	cout.flush();
	
	int opponent;
	scanf( "%d" , &opponent );
	
	goo( player , opponent );
	
	return 0;

}
