#include <bits/stdc++.h>
#define  maxn	   503
#define  fi        first
#define  se	   	   second
#define  pb		   push_back
using	 namespace std;
typedef  long long LL;
typedef  pair<int,int> pi;

int n,m;
int dist[maxn][maxn];

int main() {
	memset( dist , -1 , sizeof(dist) );
	scanf( "%d%d" , &n , &m );
	for( int i = 1 ; i <= n ; i++ )
		dist[i][i] = 0;
	for( int i = 0 , x , y , z ; i < m ; i++ ) {
		scanf( "%d%d%d" , &x , &y , &z );
		if( x != y && ( dist[x][y] == -1 || z < dist[x][y] ) )
			dist[x][y] = dist[y][x] = z;
	}
	for( int k = 1 ; k <= n ; k++ )
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 1 ; j <= n ; j++ )
				if( dist[i][k] != -1 && dist[k][j] != -1 ) {
					int sum = dist[i][k] + dist[k][j];
					if( dist[i][j] == -1 || sum < dist[i][j] )
						dist[i][j] = sum;
				}
	for( int i = 1 ; i <= n ; i++ , puts("") )
		for( int j = 1 ; j <= n ; j++ )
			printf( "%d " , dist[i][j] );
	return 0;
}
