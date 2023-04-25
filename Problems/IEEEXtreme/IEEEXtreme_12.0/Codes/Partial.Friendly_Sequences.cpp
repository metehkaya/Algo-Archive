#include <bits/stdc++.h>
#define maxn 2001
#define mod 1000000007
using namespace std;

int n,mx,n0;
int b[100001];
map<int,int> dp[maxn][maxn];

int f( int id , int curr , int sum ) {
	if( sum > b[id] )
		return 0;
	if( id == n )
		return max( 0 , b[id] - sum + 1 );
	if( dp[id-n0][curr].find( sum ) != dp[id-n0][curr].end() )
		return dp[id-n0][curr][sum];
	dp[id-n0][curr][sum] = f( id + 1 , curr , sum + curr );
	if( sum + 1 <= b[id] && sum + curr * (n - id) + (n - id + 1) <= mx )
		dp[id-n0][curr][sum] = ( dp[id-n0][curr][sum] + f( id , curr + 1 , sum + 1 ) ) % mod;
	return dp[id-n0][curr][sum];
}

int main() {
	scanf( "%d" , &n );
	for( int i = 1 ; i <= n ; i++ ) {
		scanf( "%d" , &b[i] );
		mx = max( mx , b[i] );
	}
	n0 = max( n - mx , 0 );
	printf( "%d\n" , f( n0 + 1 , 0 , 0 ) );
	return 0;
}