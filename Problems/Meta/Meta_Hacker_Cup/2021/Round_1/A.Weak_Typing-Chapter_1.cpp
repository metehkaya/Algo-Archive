#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n >> s;
		int ans = 0 , state = 0;
		for( int i = 0 ; i < n ; i++ ) {
			char c = s[i];
			if(state == 0) {
				if(c == 'F')
					state = 0;
				else if(c == 'X')
					state = -1;
				else
					state = +1;
			}
			else if(state == -1) {
				if(c == 'F')
					state = -1;
				else if(c == 'X')
					state = -1;
				else
					state = +1 , ans++;
			}
			else {
				if(c == 'F')
					state = +1;
				else if(c == 'X')
					state = -1 , ans++;
				else
					state = +1;
			}
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
