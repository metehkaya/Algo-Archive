#include <bits/stdc++.h>
using namespace std;

int T,n;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		int lm = -1 , rm = -1 , cnt = 0;
		for( int i = 1 , x ; i <= n ; i++ ) {
			scanf("%d",&x);
			if(x) {
				cnt++;
				rm = i;
				if(lm == -1)
					lm = i;
			}
		}
		printf("%d\n",rm-lm+1-cnt);
	}
	return 0;
}
