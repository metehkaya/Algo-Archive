#include <bits/stdc++.h>
#define maxn 3001
#define maxs 9000001
#define mod 1000000007
using namespace std;
typedef long long LL;

LL ans;
int T,n,k,N,M,K;
int c[maxn];
int w[maxn];
LL fact[maxs];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void precalc() {
	fact[0] = 1;
	for( int i = 1 ; i < maxs ; i++ )
		fact[i] = (fact[i-1] * i) % mod;
}

void reset() {
	N = M = K = 0;
}

void input() {
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d%d",&c[i],&w[i]);
		N += c[i];
		if(w[i] <= w[1])
			M += c[i];
		if(w[i] == w[1])
			K += c[i];
	}
}

LL getCalc(LL x , int y) {
	if(y == 0)
		return 1;
	LL res = getCalc(x,y/2);
	res = (res*res) % mod;
	if(y & 1)
		res = (res*x) % mod;
	return res;
}

void solve() {
	if(M < k+1) {
		ans = 0;
		return;
	}
	if(M-K < k+1) {
		LL p = fact[M] * fact[N-k-1] % mod;
		LL q = fact[M-k-1] * fact[N] % mod;
		q = getCalc(q,mod-2);
		ans = p*q % mod;
	}
	else {
		LL a = fact[M]*fact[M-K-k-1] % mod;
		LL b = fact[M-K]*fact[M-k-1] % mod;
		a = (a-b+mod) % mod;
		LL p = a*fact[N-k-1] % mod;
		LL q = fact[M-k-1] * fact[M-K-k-1] % mod;
		q = q * fact[N] % mod;
		q = getCalc(q,mod-2);
		ans = p*q % mod;
	}
	LL pp = c[1];
	LL qq = K;
	qq = getCalc(qq,mod-2);
	LL mult = pp*qq % mod;
	ans = ans*mult % mod;
}

int main() {
	io();
	precalc();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
