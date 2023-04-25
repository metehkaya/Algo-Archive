#include <bits/stdc++.h>
#define maxn 10001
#define pb push_back
using namespace std;

int n;
bool mark[maxn][maxn];
vector<int> adj[maxn];

int main() {
	
	scanf( "%d" , &n );
	
	for( int x , y ; true ;  ) {
		scanf( "%d%d" , &x , &y );
		if( adj[x].size() > adj[y].size() )
			swap( x , y );
		for( int i = 0 ; i < adj[x].size() ; i++ )
			if( mark[y][ adj[x][i] ] ) {
				cout << 0 << endl;
				cout.flush();
				return 0;
			}
		cout << 1 << endl;
		cout.flush();
		adj[x].pb( y );
		adj[y].pb( x );
		mark[x][y] = mark[y][x] = true;
	}
	
	return 0;

}
