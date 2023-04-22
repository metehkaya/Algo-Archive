#include <bits/stdc++.h>
#define mod 1000000007LL
using namespace std;
typedef long long LL;

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
		LL ans = 0;
		int state = 0;
		int idx = -1;
		for( int i = 0 ; i < n ; i++ ) {
			char c = s[i];
			if(state == 0) {
				if(c == 'F')
					state = 0;
				else if(c == 'X')
					state = -1 , idx = i;
				else
					state = +1 , idx = i;
			}
			else if(state == -1) {
				if(c == 'F')
					state = -1;
				else if(c == 'X')
					state = -1 , idx = i;
				else {
					state = +1;
					ans += (LL) (idx+1) * (n-i);
					ans %= mod;
					idx = i;
				}
			}
			else {
				if(c == 'F')
					state = +1;
				else if(c == 'X') {
					state = -1;
					ans += (LL) (idx+1) * (n-i);
					ans %= mod;
					idx = i;
				}
				else
					state = +1 , idx = i;
			}
		}
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
