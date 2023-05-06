#include <bits/stdc++.h>
#define maxn 100000
#define mod 998244353
using namespace std;
typedef long long LL;

int T,n,x;
int a[maxn];

int calcPow(int a , int b) {
	if(b == 0)
		return 1;
	int res = calcPow(a,b/2);
	res = (LL) res * res % mod;
	if(b & 1)
		res = (LL) res * a % mod;
	return res;
}

int solve() {
	int term = a[0];
	LL ans = calcPow(term,n);
	for( int i = 1 ; i < n ; i++ ) {
		term = (LL) term * x % mod;
		term = (term + a[0]) % mod;
		int mult = calcPow(term,n-i);
		ans = (LL) ans * mult % mod;
	}
	ans = (LL) ans * ans % mod;
	return ans;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&x);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&a[i]);
		printf("%d\n",solve());
	}
	return 0;
}
