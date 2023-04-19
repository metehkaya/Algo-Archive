#include <bits/stdc++.h>
#define maxlog 60
#define mod 1000000007
using namespace std;
typedef long long LL;

struct Mat {
	vector< vector<int> > ways;
	Mat(int n, bool isI) {
		ways.resize(n, vector<int>(n,0));
		if(isI)
			for( int i = 0 ; i < n ; i++ )
				ways[i][i] = 1;
	}
};

LL m;
int n,tot;
Mat* dp[maxlog];

Mat* mult(Mat* a, Mat* b) {
	Mat* res = new Mat(n,false);
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < n ; j++ )
			for( int k = 0 ; k < n ; k++ ) {
				int v1 = a->ways[i][k];
				int v2 = b->ways[k][j];
				int add = ( (LL) v1 * v2 ) % mod;
				int curr = res->ways[i][j];
				res->ways[i][j] = ( curr + add ) % mod;
			}
	return res;
}

int main() {
	scanf("%d%lld",&n,&m);
	dp[0] = new Mat(n,false);
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < n ; j++ )
			scanf("%d",&dp[0]->ways[i][j]);
	for( int i = 1 ; (1LL<<i) <= m ; i++ )
		dp[i] = mult(dp[i-1], dp[i-1]);
	Mat* ans = new Mat(n,true);
	for( int i = 0 ; (1LL<<i) <= m ; i++ )
		if( m & (1LL<<i) )
			ans = mult(ans, dp[i]);
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < n ; j++ )
			tot = ( tot + ans->ways[i][j] ) % mod;
	printf("%d\n",tot);
	return 0;
}
