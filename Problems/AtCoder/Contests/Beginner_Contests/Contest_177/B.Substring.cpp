#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
string s,t;

int main() {
	cin >> s >> t;
	n = s.length();
	m = t.length();
	ans = INT_MAX;
	for( int i = 0 ; i <= n-m ; i++ ) {
		int cnt = 0;
		for( int j = 0 ; j < m ; j++ )
			cnt += s[i+j] != t[j];
		ans = min(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}
