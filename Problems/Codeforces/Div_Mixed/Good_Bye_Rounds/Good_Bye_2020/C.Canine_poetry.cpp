#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;

int main() {
	cin >> T;
	for( int tc = 0 ; tc < T ; tc++ ) {
		cin >> s;
		n = s.length();
		int ans = 0;
		for( int i = 1 ; i < n ; i++ ) {
			if(i == 1 && s[i] == s[i-1])
				s[i] = '#' , ans++;
			else if(i > 1 && (s[i] == s[i-1] || s[i] == s[i-2]))
				s[i] = '#' , ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
