#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int T,n;
string s;
vector<string> ans;
vector<string> s10;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void precalc() {
	for( int bmask = 0 ; bmask < 1024 ; bmask++ ) {
		string t = "";
		for( int i = 0 ; i < 10 ; i++ )
			if(bmask & (1<<i))
				t.pb('.');
			else
				t.pb('-');
		s10.pb(t);
	}
}

void reset() {
	ans.clear();
}

void solve() {
	int len = s.length();
	len = min(len, 10);
	s = s.substr(0, len);
	for( int i = 0 ; i < 1024 && (int) ans.size() < n-1 ; i++ ) {
		string t = s10[i].substr(0, len);
		if(s != t)
			ans.pb(s10[i]);
	}
}

int main() {
	io();
	precalc();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		cin >> n >> s;
		solve();
		printf("Case #%d:\n",tc);
		for( int i = 0 ; i < n-1 ; i++ )
			cout << ans[i] << endl;
	}
	return 0;
}
