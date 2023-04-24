#include <bits/stdc++.h>
#define pb push_back
#define mod 1000000007
using namespace std;
typedef long long LL;

int T,n,k;
string s;

LL poww(LL x , int y) {
	if(y == 0)
		return 1;
	LL res = poww(x,y/2);
	res = (res*res) % mod;
	if(y & 1)
		res = (res*x) % mod;
	return res;
}

int main() {
	cin >> T;
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n >> k >> s;
		string t = "";
		int times = (n+1)/2;
		for( int i = 0 ; i < n ; i++ )
			t.pb(' ');
		LL ans = 0;
		for( int i = 0 ; i < times ; i++ ) {
			int bef = s[i]-'a';
			t[i] = t[n-1-i] = s[i];
			ans = (ans + bef*poww(k,times-1-i)) % mod;
		}
		if(t < s)
			ans = (ans+1) % mod;
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
