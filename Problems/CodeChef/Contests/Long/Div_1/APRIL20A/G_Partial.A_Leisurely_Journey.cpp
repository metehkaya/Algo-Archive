#include <bits/stdc++.h>
#define maxl 60
#define maxq 500
#define maxn 4000
#define pb push_back
#define mod 1000000007
using namespace std;
typedef long long LL;

struct Row {
	int n;
	vector<int> vals;
	Row(int n, bool isI) {
		this->n = n;
		vals.resize(n,0);
		if(isI)
			vals[0] = 1;
	}
};

struct Mat {
	int n;
	vector< vector<int> > vals;
	Mat(int n, bool isI) {
		this->n = n;
		vals.resize(n, vector<int>(n,0));
		if(isI)
			for( int i = 0 ; i < n ; i++ )
				vals[i][i] = 1;
	}
};

LL mxd;
int n,m,q;
LL d[maxq];
int ar[maxn];
vector<int> adj[maxn];

void solve1() {
	vector< vector<int> > dp( n , vector<int>(mxd+1,0) );
	dp[n-1][0] = 1;
	for( int day = 1 ; day <= mxd ; day++ )
		for( int u = 0 ; u < n ; u++ ) {
			dp[u][day] = ( (LL) dp[u][day-1] * ar[u] ) % mod;
			int sz = (int) adj[u].size();
			for( int i = 0 ; i < sz ; i++ ) {
				int v = adj[u][i];
				dp[u][day] = ( dp[u][day] + dp[v][day-1] ) % mod;
			}
		}
	for( int i = 0 ; i < q ; i++ )
		printf("%d\n",dp[0][d[i]]);
}

Mat* multMatMat(Mat* a, Mat* b) {
	Mat* res = new Mat(n,false);
	for( int i = 0 ; i < n ; i++ )
		for( int j = i ; j < n ; j++ )
			if( a->vals[i][j] )
				for( int k = j ; k < n ; k++ ) {
					int v1 = a->vals[i][j];
					int v2 = b->vals[j][k];
					int add = ( (LL) v1 * v2 ) % mod;
					int curr = res->vals[i][k];
					res->vals[i][k] = ( curr + add ) % mod;
				}
	return res;
}

Row* multRowMat(Row* a, Mat* b) {
	Row* res = new Row(n,false);
	for( int i = 0 ; i < n ; i++ )
		for( int j = i ; j < n ; j++ )
			if( b->vals[i][j] ) {
				int v1 = a->vals[i];
				int v2 = b->vals[i][j];
				int add = ( (LL) v1 * v2 ) % mod;
				int curr = res->vals[j];
				res->vals[j] = ( curr + add ) % mod;
			}
	return res;
}

void solve2() {
	Mat* mat[maxl];
	mat[0] = new Mat(n,false);
	for( int u = 0 ; u < n ; u++ ) {
		mat[0]->vals[u][u] = ar[u];
		int sz = (int) adj[u].size();
		for( int i = 0 ; i < sz ; i++ ) {
			int v = adj[u][i];
			mat[0]->vals[u][v] = 1;
		}
	}
	for( int i = 1 ; i < maxl ; i++ )
		mat[i] = multMatMat(mat[i-1],mat[i-1]);
	for( int t = 0 ; t < q ; t++ ) {
		Row* ans = new Row(n,true);
		for( int i = 0 ; i < 60 ; i++ )
			if( d[t] & (1LL << i) ) {
				Row* tmp = ans;
				ans = multRowMat(tmp, mat[i]);
				delete tmp;
			}
		printf("%d\n",ans->vals[n-1]);
		delete ans;
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&q);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 1 ; i <= m ; i++ ) {
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x-1].pb(y-1);
	}
	for( int i = 0 ; i < q ; i++ ) {
		scanf("%lld",&d[i]);
		mxd = max( mxd , d[i] );
	}
	if(mxd <= 2000)
		solve1();
	else if(n <= 100)
		solve2();
	return 0;
}
