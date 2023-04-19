#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;
LL n,s,k;

LL gcd(LL x , LL y) {
	if(!y)
		return x;
	return gcd(y,x%y);
}

LL getInv(LL a , LL mod) {
	LL b = mod;
	LL p = 1 , q = 0;
	while(b > 0) {
		LL c = a / b;
		LL d;
		d = a;
		a = b;
		b = d % b;
		d = p;
		p = q;
		q = d - c * q;
	}
	return p < 0 ? p + mod : p;
}

int main() {
	cin >> T;
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n >> s >> k;
		LL g = gcd(n,k);
		if(s % g) {
			puts("-1");
			continue;
		}
		n /= g , s /= g , k /= g;
		LL inv = getInv(k,n);
		LL ans = inv * (n-s) % n;
		cout << ans << endl;
	}
	return 0;
}
