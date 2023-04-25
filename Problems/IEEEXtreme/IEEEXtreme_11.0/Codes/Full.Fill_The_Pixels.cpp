#include <bits/stdc++.h>
#define maxn 1000
using namespace std;

int T,n,m;
int ans[3];
string str[maxn];
string original[maxn];

int cntdir[3] = { 4 , 4 , 8 };
int dir[3][8][2] = { 	{ { 0 , -1 } , { -1 , 0 } , { 1 , 0 } , { 0 , 1 } , { 0 , 0 } , { 0 , 0 } , { 0 , 0 } , { 0 , 0 } } ,
				    	{ { -1 , -1 } , { -1 , 1 } , { 1 , -1 } , { 1 , 1 } , { 0 , 0 } , { 0 , 0 } , { 0 , 0 } , { 0 , 0 } } ,
				 		{ { 0 , -1 } , { -1 , 0 } , { 1 , 0 } , { 0 , 1 } , { -1 , -1 } , { -1 , 1 } , { 1 , -1 } , { 1 , 1 } } };

void dfs( int r , int c , int way ) {
	str[r][c] = '0';
	for( int i = 0 ; i < cntdir[way] ; i++ ) {
		int x = r + dir[way][i][0];
		int y = c + dir[way][i][1];
		if( x < 0 || x >= n || y < 0 || y >= m )
			continue;
		if( str[x][y] == '1' )
			dfs( x , y , way );
	}
}

int main() {
	
	scanf( "%d" , &T );
	
	for( int tc = 1 ; tc <= T ; tc++ ) {
		
		scanf( "%d%d" , &m , &n );
		for( int i = 0 ; i < n ; i++ )
			cin >> original[i];
		
		ans[0] = ans[1] = ans[2] = 0;
		
		for( int dirs = 0 ; dirs < 3 ; dirs++ ) {
			for( int i = 0 ; i < n ; i++ )
				str[i] = original[i];
			for( int i = 0 ; i < n ; i++ )
				for( int j = 0 ; j < m ; j++ )
					if( str[i][j] == '1' ) {
						ans[dirs]++;
						dfs( i , j , dirs );
					}
		}
		
		printf( "%d %d %d\n" , ans[0] , ans[1] , ans[2] );
		
	}
	
	return 0;

}
