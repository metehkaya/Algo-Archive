#include <bits/stdc++.h>
#define maxn 1000003
#define mod 1000000007
using namespace std;
typedef long long LL;

int n;
LL ans;
LL pw8[maxn];
LL pw9[maxn];
LL fact[maxn];

LL calc(LL x , int y) {
	if(!y)
		return 1;
	LL res = calc(x,y/2);
	res = res*res % mod;
	if(y&1)
		res = res*x % mod;
	return res;
}

int main() {
	scanf("%d",&n);
	fact[0] = 1;
	for( int i = 1 ; i <= n ; i++ )
		fact[i] = fact[i-1]*i % mod;
	pw8[0] = 1;
	for( int i = 1 ; i <= n ; i++ )
		pw8[i] = pw8[i-1]*8 % mod;
	pw9[0] = 1;
	for( int i = 1 ; i <= n ; i++ )
		pw9[i] = pw9[i-1]*9 % mod;
	for( int i = 1 ; i < n ; i++ ) {
		LL comb = fact[n];
		LL rev = fact[i]*fact[n-i] % mod;
		comb = comb * calc(rev,mod-2) % mod;
		LL sum = pw9[n-i] - pw8[n-i] + mod;
		sum %= mod;
		ans += comb*sum % mod;
		ans %= mod;
	}
	printf("%lld\n",ans);
	return 0;
}
