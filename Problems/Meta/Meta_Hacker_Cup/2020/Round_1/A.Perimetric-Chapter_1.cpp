#include <bits/stdc++.h>
#define maxn 1000001
#define mod 1000000007LL
using namespace std;
typedef long long LL;

int T,n,k;
LL ans,w;
LL al,bl,cl,dl;
LL ah,bh,ch,dh;
LL l[maxn];
LL h[maxn];
LL mx[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	ans = 1;
	for( int i = 1 ; i <= n ; i++ )
		mx[i] = 0;
}

void input() {
	scanf("%d%d%lld",&n,&k,&w);
	for( int i = 1 ; i <= k ; i++ )
		scanf("%lld",&l[i]);
	scanf("%lld%lld%lld%lld",&al,&bl,&cl,&dl);
	for( int i = 1 ; i <= k ; i++ )
		scanf("%lld",&h[i]);
	scanf("%lld%lld%lld%lld",&ah,&bh,&ch,&dh);
	for( int i = k+1 ; i <= n ; i++ ) {
		l[i] = al*l[i-2] + bl*l[i-1] + cl;
		l[i] = l[i] % dl + 1;
	}
	for( int i = k+1 ; i <= n ; i++ ) {
		h[i] = ah*h[i-2] + bh*h[i-1] + ch;
		h[i] = h[i] % dh + 1;
	}
}

void solve() {
	LL sumx = 0 , sumy = 0 , last = 0;
	for( int i = 1 ; i <= n ; i++ ) {
		if(i == 1 || l[i] > last) {
			sumx += w;
			sumy += h[i];
		}
		else {
			sumx += (l[i]+w) - last;
			sumy += max(h[i]-mx[i],0LL);
		}
		last = l[i] + w;
		for( int j = i+1 ; j <= n && l[j] <= l[i]+w ; j++ )
			mx[j] = max( mx[j] , h[i] );
		LL curr = 2 * (sumx + sumy);
		curr %= mod;
		ans = (ans * curr) % mod;
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
