#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;
vector<string> ans;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	ans.clear();
}

void solve() {
	char start,finish;
	if(s[0] == '.')
		start = '-' , finish = '.';
	else
		start = '.' , finish = '-';
	for( int i = 1 ; i < n ; i++ ) {
		string t = "";
		for( int j = 0 ; j < i ; j++ )
			t.push_back(start);
		for( int j = i ; j < n ; j++ )
			t.push_back(finish);
		ans.push_back(t);
	}
}

int main() {
	io();
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
