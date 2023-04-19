#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 3001
#define maxh 200003
#define mod 1000000007
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int n,h,w;
int dp[maxn];
int fac[maxh];
int invFac[maxh];
vector<pi> forb;

bool comp( pi a , pi b ) {
	return a.fi + a.se < b.fi + b.se;
}

int sub(int a, int b) {
	return (a - b + mod) % mod;
}

int mult(int a, int b) {
	return (LL) a * b % mod;
}

int calcPow(int a, int b) {
	if(b == 0)
		return 1;
	int res = calcPow(a, b/2);
	res = mult(res, res);
	if(b & 1)
		res = mult(res, a);
	return res;
}

int calcInverse(int a) {
	return calcPow(a, mod-2);
}

int calcComb(int a, int b) {
	if(a < 0 || b < 0 || b > a)
		return 0;
	return mult( fac[a] , mult( invFac[b] , invFac[a-b] ) );
}

int calcNoOfPaths(int row, int col) {
	return calcComb(row+col, row);
}

int main() {
	fac[0] = invFac[0] = 1;
	for( int i = 1 ; i < maxh ; i++ ) {
		fac[i] = mult( fac[i-1] , i );
		invFac[i] = calcInverse( fac[i] );
	}
	scanf("%d%d%d",&h,&w,&n);
	for( int i = 0 ; i < n ; i++ ) {
		int x,y;
		scanf("%d%d",&x,&y);
		forb.pb(pi(x,y));
	}
	forb.pb(pi(h,w));
	sort( forb.begin() , forb.end() , comp );
	for( int i = 0 ; i <= n ; i++ ) {
		dp[i] = calcNoOfPaths(forb[i].fi-1, forb[i].se-1);
		for( int j = 0 ; j < i ; j++ ) {
			int diffRow = forb[i].fi - forb[j].fi;
			int diffCol = forb[i].se - forb[j].se;
			int noOfPaths = calcNoOfPaths(diffRow, diffCol);
			dp[i] = sub( dp[i] , mult(dp[j], noOfPaths) );
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}
