#include <bits/stdc++.h>
#define maxs 100000
using namespace std;
typedef long long LL;

int n,m,s=1;
int dims[5];
int ar[maxs];

void solve5() {
	
	LL sum[dims[0]+1][dims[1]+1][dims[2]+1][dims[3]+1][dims[4]+1];
	memset( sum , 0 , sizeof(sum) );
	
	for( int i = 0 ; i < s ; i++ ) {
		int val = ar[i];
		int rem = i , x1 , x2 , x3 , x4 , x5;
		x5 = rem % dims[4];
		rem -= x5;
		rem /= dims[4];
		x4 = rem % dims[3];
		rem -= x4;
		rem /= dims[3];
		x3 = rem % dims[2];
		rem -= x3;
		rem /= dims[2];
		x2 = rem % dims[1];
		rem -= x2;
		rem /= dims[1];
		x1 = rem;
		x1++,x2++,x3++,x4++,x5++;
		sum[x1][x2][x3][x4][x5] = + sum[x1-1][x2][x3][x4][x5] + sum[x1][x2-1][x3][x4][x5] + sum[x1][x2][x3-1][x4][x5] + sum[x1][x2][x3][x4-1][x5] + sum[x1][x2][x3][x4][x5-1]
						  	  	  - sum[x1-1][x2-1][x3][x4][x5] - sum[x1-1][x2][x3-1][x4][x5] - sum[x1][x2-1][x3-1][x4][x5] - sum[x1-1][x2][x3][x4-1][x5] - sum[x1][x2-1][x3][x4-1][x5] - sum[x1][x2][x3-1][x4-1][x5] - sum[x1-1][x2][x3][x4][x5-1] - sum[x1][x2-1][x3][x4][x5-1] - sum[x1][x2][x3-1][x4][x5-1] - sum[x1][x2][x3][x4-1][x5-1]
						  	  	  + sum[x1-1][x2-1][x3-1][x4][x5] + sum[x1-1][x2-1][x3][x4-1][x5] + sum[x1-1][x2][x3-1][x4-1][x5] + sum[x1][x2-1][x3-1][x4-1][x5] + sum[x1-1][x2-1][x3][x4][x5-1] + sum[x1-1][x2][x3-1][x4][x5-1] + sum[x1][x2-1][x3-1][x4][x5-1] + sum[x1-1][x2][x3][x4-1][x5-1] + sum[x1][x2-1][x3][x4-1][x5-1] + sum[x1][x2][x3-1][x4-1][x5-1]
						  	  	  - sum[x1-1][x2-1][x3-1][x4-1][x5] - sum[x1-1][x2-1][x3-1][x4][x5-1] - sum[x1-1][x2-1][x3][x4-1][x5-1] - sum[x1-1][x2][x3-1][x4-1][x5-1] - sum[x1][x2-1][x3-1][x4-1][x5-1]
								  + sum[x1-1][x2-1][x3-1][x4-1][x5-1]
							  	  + val;
	}
	
	scanf( "%d" , &m );
	for( int i = 0 , x1 , x2 , x3 , x4 , x5 , y1 , y2 , y3 , y4 , y5 ; i < m ; i++ ) {
		scanf( "%d%d%d%d%d" , &x1 , &x2 , &x3 , &x4 , &x5 );
		scanf( "%d%d%d%d%d" , &y1 , &y2 , &y3 , &y4 , &y5 );
		printf( "%lld\n" , + sum[y1][y2][y3][y4][y5]
						 - sum[x1-1][y2][y3][y4][y5] - sum[y1][x2-1][y3][y4][y5] - sum[y1][y2][x3-1][y4][y5] - sum[y1][y2][y3][x4-1][y5] - sum[y1][y2][y3][y4][x5-1]
						 + sum[x1-1][x2-1][y3][y4][y5] + sum[x1-1][y2][x3-1][y4][y5] + sum[y1][x2-1][x3-1][y4][y5] + sum[x1-1][y2][y3][x4-1][y5] + sum[y1][x2-1][y3][x4-1][y5] + sum[y1][y2][x3-1][x4-1][y5] + sum[x1-1][y2][y3][y4][x5-1] + sum[y1][x2-1][y3][y4][x5-1] + sum[y1][y2][x3-1][y4][x5-1] + sum[y1][y2][y3][x4-1][x5-1]
						 - sum[x1-1][x2-1][x3-1][y4][y5] - sum[x1-1][x2-1][y3][x4-1][y5] - sum[x1-1][y2][x3-1][x4-1][y5] - sum[y1][x2-1][x3-1][x4-1][y5] - sum[x1-1][x2-1][y3][y4][x5-1] - sum[x1-1][y2][x3-1][y4][x5-1] - sum[y1][x2-1][x3-1][y4][x5-1] - sum[x1-1][y2][y3][x4-1][x5-1] - sum[y1][x2-1][y3][x4-1][x5-1] - sum[y1][y2][x3-1][x4-1][x5-1]
						 + sum[x1-1][x2-1][x3-1][x4-1][y5] + sum[x1-1][x2-1][x3-1][y4][x5-1] + sum[x1-1][x2-1][y3][x4-1][x5-1] + sum[x1-1][y2][x3-1][x4-1][x5-1] + sum[y1][x2-1][x3-1][x4-1][x5-1]
						 - sum[x1-1][x2-1][x3-1][x4-1][x5-1] );
	}
	
}

void solve4() {
	
	int sum[dims[0]+1][dims[1]+1][dims[2]+1][dims[3]+1];
	memset( sum , 0 , sizeof(sum) );
	
	for( int i = 0 ; i < s ; i++ ) {
		int val = ar[i];
		int rem = i , x1 , x2 , x3 , x4;
		x4 = rem % dims[3];
		rem -= x4;
		rem /= dims[3];
		x3 = rem % dims[2];
		rem -= x3;
		rem /= dims[2];
		x2 = rem % dims[1];
		rem -= x2;
		rem /= dims[1];
		x1 = rem;
		x1++,x2++,x3++,x4++;
		sum[x1][x2][x3][x4] = + sum[x1-1][x2][x3][x4] + sum[x1][x2-1][x3][x4] + sum[x1][x2][x3-1][x4] + sum[x1][x2][x3][x4-1]
						  	  - sum[x1-1][x2-1][x3][x4] - sum[x1-1][x2][x3-1][x4] - sum[x1][x2-1][x3-1][x4] - sum[x1-1][x2][x3][x4-1] - sum[x1][x2-1][x3][x4-1] - sum[x1][x2][x3-1][x4-1]
						  	  + sum[x1-1][x2-1][x3-1][x4] + sum[x1-1][x2-1][x3][x4-1] + sum[x1-1][x2][x3-1][x4-1] + sum[x1][x2-1][x3-1][x4-1]
						  	  - sum[x1-1][x2-1][x3-1][x4-1]
							  + val;
	}
	
	scanf( "%d" , &m );
	for( int i = 0 , x1 , x2 , x3 , x4 , y1 , y2 , y3 , y4 ; i < m ; i++ ) {
		scanf( "%d%d%d%d" , &x1 , &x2 , &x3 , &x4 );
		scanf( "%d%d%d%d" , &y1 , &y2 , &y3 , &y4 );
		printf( "%d\n" , +sum[y1][y2][y3][y4]
						 -sum[x1-1][y2][y3][y4] - sum[y1][x2-1][y3][y4] - sum[y1][y2][x3-1][y4] - sum[y1][y2][y3][x4-1]
						 +sum[x1-1][x2-1][y3][y4] + sum[x1-1][y2][x3-1][y4] + sum[y1][x2-1][x3-1][y4] + sum[x1-1][y2][y3][x4-1] + sum[y1][x2-1][y3][x4-1] + sum[y1][y2][x3-1][x4-1]
						 -sum[x1-1][x2-1][x3-1][y4] - sum[x1-1][x2-1][y3][x4-1] - sum[x1-1][y2][x3-1][x4-1] - sum[y1][x2-1][x3-1][x4-1]
						 +sum[x1-1][x2-1][x3-1][x4-1] );
	}
	
}

void solve3() {
	
	int sum[dims[0]+1][dims[1]+1][dims[2]+1];
	memset( sum , 0 , sizeof(sum) );
	
	for( int i = 0 ; i < s ; i++ ) {
		int val = ar[i];
		int rem = i , x1 , x2 , x3;
		x3 = rem % dims[2];
		rem -= x3;
		rem /= dims[2];
		x2 = rem % dims[1];
		rem -= x2;
		rem /= dims[1];
		x1 = rem;
		x1++,x2++,x3++;
		sum[x1][x2][x3] = + sum[x1-1][x2][x3] + sum[x1][x2-1][x3] + sum[x1][x2][x3-1]
						  - sum[x1-1][x2-1][x3] - sum[x1-1][x2][x3-1] - sum[x1][x2-1][x3-1]
						  + sum[x1-1][x2-1][x3-1]
						  + val;
	}
	
	scanf( "%d" , &m );
	for( int i = 0 , x1 , x2 , x3 , y1 , y2 , y3 ; i < m ; i++ ) {
		scanf( "%d%d%d" , &x1 , &x2 , &x3 );
		scanf( "%d%d%d" , &y1 , &y2 , &y3 );
		printf( "%d\n" , +sum[y1][y2][y3]
						 -sum[x1-1][y2][y3] - sum[y1][x2-1][y3] - sum[y1][y2][x3-1]
						 +sum[x1-1][x2-1][y3] + sum[x1-1][y2][x3-1] + sum[y1][x2-1][x3-1]
						 -sum[x1-1][x2-1][x3-1] );
	}
	
}

void solve2() {
	
	int sum[dims[0]+1][dims[1]+1];
	memset( sum , 0 , sizeof(sum) );
	
	for( int i = 0 ; i < s ; i++ ) {
		int x1 = i / dims[1] + 1;
		int x2 = i % dims[1] + 1;
		int val = ar[i];
		sum[x1][x2] = sum[x1-1][x2] + sum[x1][x2-1] - sum[x1-1][x2-1] + val;
	}
	
	scanf( "%d" , &m );
	for( int i = 0 , x1 , x2 , y1 , y2 ; i < m ; i++ ) {
		scanf( "%d%d" , &x1 , &x2 );
		scanf( "%d%d" , &y1 , &y2 );
		printf( "%d\n" , sum[y1][y2] - sum[x1-1][y2] - sum[y1][x2-1] + sum[x1-1][x2-1] );
	}
	
}

void solve1() {
	
	int sum[dims[0]+1];
	
	sum[0] = 0;
	for( int i = 1 ; i <= dims[0] ; i++ )
		sum[i] = sum[i-1] + ar[i-1];
	
	scanf( "%d" , &m );
	for( int i = 0 , x1 , y1 ; i < m ; i++ ) {
		scanf( "%d" , &x1 );
		scanf( "%d" , &y1 );
		printf( "%d\n" , sum[y1] - sum[x1-1] );
	}
	
}

int main() {

	scanf( "%d" , &n );
	for( int i = 0 ; i < n ; i++ ) {
		scanf( "%d" , &dims[i] );
		s *= dims[i];
	}
	for( int i = 0 ; i < s ; i++ )
		scanf( "%d" , &ar[i] );
	
	if( n == 1 )
		solve1();
	else if( n == 2 )
		solve2();
	else if( n == 3 )
		solve3();
	else if( n == 4 )
		solve4();
	else
		solve5();
	
	return 0;

}
