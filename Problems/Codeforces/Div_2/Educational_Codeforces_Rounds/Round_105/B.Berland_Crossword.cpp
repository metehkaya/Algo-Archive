#include <bits/stdc++.h>
using namespace std;

int T,n;
int cnt[4];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < 4 ; i++ )
			scanf("%d",&cnt[i]);
		bool ok = false;
		for( int bmask = 0 ; bmask < 16 ; bmask++ ) {
			int least[4] = {0,0,0,0};
			int most[4] = {n,n,n,n};
			for( int i = 0 ; i < 4 ; i++ )
				if(bmask & (1<<i)) {
					int j = (i+1)%4;
					least[i]++;
					least[j]++;
				}
				else {
					int j = (i+1)%4;
					most[i]--;
					most[j]--;
				}
			ok = true;
			for( int i = 0 ; i < 4 ; i++ )
				if(least[i] > cnt[i] || cnt[i] > most[i]) {
					ok = false;
					break;
				}
			if(ok)
				break;
		}
		if(ok)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
