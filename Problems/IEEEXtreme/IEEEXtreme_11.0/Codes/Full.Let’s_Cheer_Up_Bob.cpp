#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int row[9];
int col[9];
int mvrow[9];
int mvcol[9];
int mark[3][3];

vector<int> v[6];

void fChoose( int ind , int cnt , int bmask ) {
	if( ind == 9 ) {
		if( cnt >= 3 && cnt <= 5 )
			v[cnt].pb( bmask );
		return;
	}
	fChoose( ind + 1 , cnt , bmask );
	fChoose( ind + 1 , cnt + 1 , bmask | (1 << ind) );
}

bool checkGrid( int color ) {
	if( mark[0][0] == color && mark[0][1] == color && mark[0][2] == color )
		return true;
	if( mark[1][0] == color && mark[1][1] == color && mark[1][2] == color )
		return true;
	if( mark[2][0] == color && mark[2][1] == color && mark[2][2] == color )
		return true;
	if( mark[0][0] == color && mark[1][0] == color && mark[2][0] == color )
		return true;
	if( mark[0][1] == color && mark[1][1] == color && mark[2][1] == color )
		return true;
	if( mark[0][2] == color && mark[1][2] == color && mark[2][2] == color )
		return true;
	if( mark[0][0] == color && mark[1][1] == color && mark[2][2] == color )
		return true;
	if( mark[0][2] == color && mark[1][1] == color && mark[2][0] == color )
		return true;
	return false;
}

bool tryThis( int cnt ) {
	
	for( int vi = 0 ; vi < v[cnt].size() ; vi++ ) {
		
		memset( mark , 0 , sizeof(mark) );
		mark[ row[0] ][ col[0] ] = 1;
		
		int bmask = v[cnt][vi];
		for( int i = 1 ; i < 9 ; i++ )
			if( bmask & (1 << i) )
				mark[ row[i] ][ col[i] ] = 1;
		
		for( int i = 1 , j = 1 ; i < 9 && j < cnt ; i++ )
			if( !mark[ row[i] ][ col[i] ] ) {
				j++;
				mark[ row[i] ][ col[i] ] = 2;
			}
		
		bool cond = true;
		for( int i = 0 , j1 = 0 , j2 = 0 ; i < 9 && j1 < cnt ; i++ ) {
			if( !mark[ row[i] ][ col[i] ] ) {
				cond = false;
				break;
			}
			if( mark[ row[i] ][ col[i] ] == 1 )
				j1++;
			else {
				if( j1 == j2 ) {
					cond = false;
					break;
				}
				j2++;
			}
		}
		
		if( !cond )
			continue;
		
		if( checkGrid( 1 ) && !checkGrid( 2 ) )
			return true;
		
	}
	
	return false;
	
}

void printMat() {
	puts("");
	for( int i = 0 ; i < 3 ; i++ , puts("") )
		for( int j = 0 ; j < 3 ; j++ )
			printf( "%d" , mark[i][j] );
}

bool goo( int id , int total ) {
	
	if( id == total ) {
		if( checkGrid( 1 ) && !checkGrid( 2 ) )
			return true;
		return false;
	}
	
	int color;
	
	if( id % 2 )
		color = 1;
	else
		color = 2;
	
	if( color == 1 ) {
		for( int i = 1 ; i < 9 ; i++ )
			if( !mark[ row[i] ][ col[i] ] ) {
				mark[ row[i] ][ col[i] ] = 1;
				if( goo( id + 1 , total ) )
					return true;
				mark[ row[i] ][ col[i] ] = 0;
				return false;
			}
	}
	else {
		for( int i = 0 ; i < 3 ; i++ )
			for( int j = 0 ; j < 3 ; j++ )
				if( !mark[i][j] ) {
					mark[i][j] = 2;
					mvrow[id/2] = i;
					mvcol[id/2] = j;
					if( goo( id + 1 , total ) )
						return true;
					mark[i][j] = 0;
				}
	}
	
	return false;
	
}

int main() {
	
	for( int i = 0 ; i < 9 ; i++ ) {
		scanf( "%d%d" , &row[i] , &col[i] );
		row[i]-- , col[i]--;
	}
	
	fChoose( 1 , 1 , 1 );
	
	int step;
	for( int i = 3 ; i <= 5 ; i++ )
		if( tryThis( i ) ) {
			step = i;
			break;
		}
	
	memset( mark , 0 , sizeof(mark) );
	mark[ row[0] ][ col[0] ] = 1;
	goo( 2 , 2 * step );
	
	for( int i = 1 ; i < step ; i++ )
		printf( "%d %d\n" , mvrow[i] + 1 , mvcol[i] + 1 );
	
	return 0;

}
