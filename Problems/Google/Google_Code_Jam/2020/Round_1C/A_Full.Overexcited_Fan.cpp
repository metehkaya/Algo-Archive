#include <bits/stdc++.h>
using namespace std;

int T,n,x,y;
string s;
int dir[256][2];

int main() {
	dir['E'][0] = 1;
	dir['W'][0] = -1;
	dir['N'][1] = 1;
	dir['S'][1] = -1;
	cin >> T;
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> x >> y >> s;
		n = s.length();
		int ans = -1;
		for( int i = 0 ; i < n ; i++ ) {
			x += dir[s[i]][0];
			y += dir[s[i]][1];
			int cost = abs(x) + abs(y);
			if(cost <= i+1) {
				ans = i+1;
				break;
			}
		}
		printf("Case #%d: ",tc);
		if(ans == -1)
			puts("IMPOSSIBLE");
		else
			printf("%d\n",ans);
	}
	return 0;	
}
