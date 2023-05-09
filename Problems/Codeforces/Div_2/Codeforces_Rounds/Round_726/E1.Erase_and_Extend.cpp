#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n,k;
string s;
vector<int> best;

bool check() {
	if(min(n,k) == 1)
		return true;
	char chmin = 'z';
	for( int i = 1 ; i < min(n,k) ; i++ )
		chmin = min(chmin,s[i]);
	return s[0] == chmin;
}

int main() {
	scanf("%d%d",&n,&k);
	cin >> s;
	if(check()) {
		for( int i = 0 ; i < k ; i++ )
			printf("%c",s[0]);
		return 0;
	}
	for( int i = 1 ; i <= n ; i++ )
		best.pb(i);
	for( int len = 1 ; best.size() > 1 && len <= k ; len++ ) {
		vector<int> v;
		char bestch = 'z';
		int sz = best.size();
		for( int i = 0 ; i < sz ; i++ ) {
			char c = s[len%best[i]];
			if(c < bestch) {
				v.clear();
				v.pb(best[i]);
				bestch = c;
			}
			else if(c == bestch)
				v.pb(best[i]);
		}
		best = v;
	}
	int len = best[0];
	for( int i = 0 ; i < k ; i++ )
		printf("%c",s[i%len]);
	return 0;
}
