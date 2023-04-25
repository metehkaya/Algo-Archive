#include <bits/stdc++.h>
#define maxp 31
#define maxn 600
using namespace std;

struct data {
	int r,c;
	double dist;
	data( int _r , int _c , double _dist ) {
		r = _r;
		c = _c;
		dist = _dist;
	}
};

bool operator<( const data &a , const data &b ) {
	return a.dist > b.dist;
}

int n,m,p;
int x[maxp];
int y[maxp];
double r[maxn][maxn];
double h[maxn][maxn];
int mark[maxn][maxn];
double cost[maxn][maxn][4];

int dir[4][2] = { {-1,0} , {0,-1} , {0,1} , {1,0} };

double findCost( int x1 , int y1 , int x2 , int y2 ) {
 	double cost1 = ( r[x1][y1] + r[x2][y2] ) / 2;
    double cost2 = exp( 3.5 * fabs( ( h[x2][y2] - h[x1][y1] ) / 10 + 0.05 ) );
	return cost1 * cost2;
}

double sssp( int dp ) {
	
	priority_queue<data>heap;
	
	heap.push( data( x[dp-1] , y[dp-1] , 0 ) );
	
	while( !heap.empty() ) {
		
		data tmp = heap.top();
		heap.pop();
		
		int r = tmp.r;
		int c = tmp.c;
		double dist = tmp.dist;
		
		if( r == x[dp] && c == y[dp] )
			return dist;
		
		if( mark[r][c] == dp )
			continue;
		mark[r][c] = dp;
		
		for( int i = 0 ; i < 4 ; i++ )
			if( cost[r][c][i] > -0.5 )
				if( mark[ r + dir[i][0] ][ c + dir[i][1] ] != dp )
					heap.push( data( r + dir[i][0] , c + dir[i][1] , dist + cost[r][c][i] ) );
		
	}
	
	return -1;

}

int main() {
	
	scanf( "%d%d%d" , &n , &m , &p );
	for( int i = 0 ; i <= p ; i++ )
		scanf( "%d%d" , &x[i] , &y[i] );
	
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			cin >> r[i][j];
	
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			cin >> h[i][j];
	
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			for( int k = 0 ; k < 4 ; k++ ) {
				int x = i + dir[k][0];
				int y = j + dir[k][1];
				if( x < 0 || x >= n || y < 0 || y >= m ) {
					cost[i][j][k] = -1;
					continue;
				}
				cost[i][j][k] = findCost( i , j , x , y );
			}
	
	double sum = 0;
	for( int i = 1 ; i <= p ; i++ ) {
		double add = sssp(i);
		sum += add;
	}
	
	int ans;
	if( (int)sum + 1e-8 >= sum )
		ans = sum;
	else
		ans = sum + 1;
	
	printf( "%d\n" , ans );
	
	return 0;

}
