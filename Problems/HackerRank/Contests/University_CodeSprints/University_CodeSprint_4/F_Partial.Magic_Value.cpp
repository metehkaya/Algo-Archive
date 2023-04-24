#include <bits/stdc++.h>
#define maxn 5003
#define mod 1000000007LL
using namespace std;
typedef long long LL;

int n;
int ar[maxn];
int GCD[maxn][maxn];

int gcd(int x , int y) {
	if(!y)
		return x;
	return gcd(y,x%y);
}

void solve() {
	LL ans = 0;
	for( int L = 1 ; L <= n ; L++ )
		for( int R = L ; R <= n ; R++ ) {
			LL mx = 0;
			LL mn = (LL) 1e18;
			for( int l = L ; l <= R ; l++ )
				for( int r = l ; r <= R ; r++ ) {
					LL val = (LL)(l-L+1)*GCD[l][r];
					mn = min(mn,val);
					mx = max(mx,val);
				}
			mn %= mod;
			mx %= mod;
			LL val = (mx-mn+mod) % mod;
			val = (val*(R-L+1)) % mod;
			ans = (ans+val) % mod;
		}
	printf("%lld\n",ans);
}

void calcGcd() {
	for( int i = 1 ; i <= n ; i++ )
		GCD[i][i] = ar[i];
	for( int k = 2 ; k <= n ; k++ )
		for( int i = 1 ; i <= n-k+1 ; i++ )
			GCD[i][i+k-1] = gcd(GCD[i][i+k-2],ar[i+k-1]);
}

void read() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
}

int main() {
	read();
	calcGcd();
	solve();
	return 0;
}
