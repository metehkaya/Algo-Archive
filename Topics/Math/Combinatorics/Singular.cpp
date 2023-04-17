#include <bits/stdc++.h>
#define maxn 100003
#define mod 1000000007
using namespace std;
typedef long long LL;

int x,y;
LL fact[maxn];

int f(int x , int y) {
	if(y == 0)
		return 1;
	LL res = f(x,y/2);
	res = (res*res) % mod;
	if(y & 1)
		res = (res*x) % mod;
	return res;
}

int main() {
	fact[0] = 1;
	for( int i = 1 ; i < maxn ; i++ )
		fact[i] = (fact[i-1] * i) % mod;
	scanf("%d%d",&x,&y);
	LL num = fact[x];
	LL den = fact[y] * fact[x-y] % mod;
	int ans = num * f(den,mod-2) % mod;
	printf("%d\n",ans);
	return 0;
}
