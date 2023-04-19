#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL m;
int n;
string s;

bool check(LL base) {
	LL curr = 0;
	for( int i = 0 ; i < n ; i++ ) {
		if(log10(curr) + log10(base) > 18.1)
			return false;
		curr = base*curr + s[i]-'0';
	}
	return curr <= m;
}

int main() {
	cin >> s >> m;
	n = s.length();
	if(n == 1) {
		printf("%d\n",(s[0]-'0') <= m);
		return 0;
	}
	int d = 0;
	for( int i = 0 ; i < n ; i++ )
		d = max(d,s[i]-'0');
	LL l = d+1 , r = 1e18+5 , last = d;
	while(l <= r) {
		LL mid = (l+r)>>1;
		if(check(mid))
			last = mid , l = mid+1;
		else
			r = mid-1;
	}
	printf("%lld\n",last-d);
	return 0;
}
