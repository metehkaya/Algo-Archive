#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define maxn 300003
#define mod 998244353
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int T,n,k,cnt,ans;
LL fact[maxn];
vector<pi> v;

void calc() {
	fact[0] = 1;
	for( int i = 1 ; i < maxn ; i++ )
		fact[i] = (fact[i-1] * i) % mod;
}

void input() {
	scanf("%d%d",&n,&k);
	for( int i = 1 , l,r ; i <= n ; i++ ) {
		scanf("%d%d",&l,&r);
		v.pb(pi(l,0));
		v.pb(pi(r,1));
	}
}

LL calcPow(LL x , int y) {
	if(y == 0)
		return 1;
	LL res = calcPow(x,y/2);
	res = (res*res) % mod;
	if(y & 1)
		res = (res*x) % mod;
	return res;
}

int comb(int x , int y) {
	if(y > x || y < 0)
		return 0;
	LL num = fact[x];
	LL den = (fact[y] * fact[x-y]) % mod;
	den = calcPow(den,mod-2);
	return (num*den)%mod;
}

void solve() {
	sort(v.begin(),v.end());
	for( int i = 0 , j = 0 ; i < 2*n ; i = j ) {
		while(j < 2*n && v[i] == v[j])
			j++;
		if(v[i].se == 0) {
			for( int l = 1 ; l <= min(k,j-i) ; l++ ) {
				LL a = comb(j-i,l);
				LL b = comb(cnt,k-l);
				int add = (a*b) % mod;
				ans = (ans + add) % mod;
			}
			cnt += j-i;
		}
		else
			cnt -= j-i;
	}
}

void output() {
	printf("%d\n",ans);
}

int main() {
	calc();
	input();
	solve();
	output();
	return 0;
}
