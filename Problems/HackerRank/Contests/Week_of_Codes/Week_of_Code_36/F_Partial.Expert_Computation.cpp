#include <bits/stdc++.h>
#define maxn 1000003
#define mod 1000000007LL
using namespace std;
typedef long long LL;

int n;
LL f[maxn];
LL g[maxn];
LL x[maxn],y[maxn],z[maxn];
LL h[maxn],c[maxn],l[maxn];

void read() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%lld",&x[i]);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%lld",&y[i]);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%lld",&z[i]);
}

void solve() {
	for( int i = 1 ; i <= n ; i++ ) {
		h[i] = (x[i] ^ g[i-1]);
		c[i] = (y[i] ^ g[i-1]);
		l[i] = (z[i] ^ g[i-1]);
		f[i] = h[1]*c[i] - c[1]*h[i];
		for( int j = 2 ; j <= i-l[i] ; j++ )
			f[i] = max(f[i] , h[j]*c[i] - c[j]*h[i]);
		g[i] = (g[i-1]+f[i]+mod*mod) % mod;
	}
}

void output() {
	g[n] = (g[n-1]+f[n]+mod*mod) % mod;
	printf("%lld\n",g[n]);
}

int main() {
	read();
	solve();
	output();
	return 0;
}
