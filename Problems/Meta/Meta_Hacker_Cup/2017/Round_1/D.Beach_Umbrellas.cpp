#include <bits/stdc++.h>
#define maxn 2001
#define mod 1000000007
using namespace std;
typedef long long LL;

int T,n,m;
int ar[maxn];
int fact[maxn];
int ifact[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int calcPow(int x , int y) {
	if(y == 0)
		return 1;
	LL res = calcPow(x,y/2);
	res = (res*res) % mod;
	if(y & 1)
		res = (res*x) % mod;
	return res;
}

int main() {
	io();
	fact[0] = ifact[0] = 1;
	for( int i = 1 ; i < maxn ; i++ ) {
		fact[i] = (LL) fact[i-1] * i % mod;
		ifact[i] = calcPow(fact[i],mod-2);
	}
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		int sumr = 0;
		scanf("%d%d",&n,&m);
		for( int i = 1 ; i <= n ; i++ ) {
			scanf("%d",&ar[i]);
			sumr += ar[i];
		}
		if(n == 1) {
			printf("Case #%d: %d\n",tc,m);
			continue;
		}
		LL ans = 0;
		sort(ar+1,ar+n+1);
		for( int i = n ; i >= 2 ; i-- ) {
			int rem = m-1 - sumr - (sumr-ar[i]-ar[i-1]);
			if(rem < 0)
				break;
			LL mult = 1;
			for( int j = rem+1 ; j <= rem+n ; j++ )
				mult = mult * j % mod;
			ans = (ans + mult) % mod;
			for( int j = i-2 ; j >= 1 ; j-- ) {
				int prevRem = rem;
				int prevMult = mult;
				rem = m-1 - sumr - (sumr-ar[i]-ar[j]);
				if(rem < 0)
					break;
				if(rem+n <= prevRem) {
					mult = 1;
					for( int k = rem+1 ; k <= rem+n ; k++ )
						mult = mult * k % mod;
				}
				else {
					int diff = prevRem - rem;
					for( int k = rem+1 ; k <= rem+diff ; k++ )
						mult = (mult * k) % mod;
					for( int k = prevRem+n ; k > prevRem+n-diff ; k-- )
						mult = (mult * calcPow(k,mod-2)) % mod;
				}
				ans = (ans + mult) % mod;
			}
		}
		ans = (2 * ans) % mod;
		ans = (ans * ifact[n]) % mod;
		ans = (ans * fact[n-2]) % mod;
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}

