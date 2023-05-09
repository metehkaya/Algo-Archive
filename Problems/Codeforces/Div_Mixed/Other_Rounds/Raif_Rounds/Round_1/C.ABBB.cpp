#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> s;
		n = s.length();
		int cnt = 0 , ans = n;
		for( int i = 0 ; i < n ; i++ )
			if(s[i] == 'A')
				cnt++;
			else {
				if(cnt)
					cnt-- , ans -= 2;
				else
					cnt++;
			}
		printf("%d\n",ans);
	}
	return 0;
}
