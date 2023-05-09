#include <bits/stdc++.h>
#define maxn 103
using namespace std;

int T,n;
int cnt[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for( int i = 0 , x ; i < n ; i++ ) {
			scanf("%d",&x);
			cnt[x]++;
		}
		int rem = 2 , ans = 0;
		for( int i = 0 ; i < maxn ; i++ ) {
			if(rem == 2 && cnt[i] < 2) {
				if(cnt[i] == 0) {
					ans = 2*i;
					break;
				}
				else {
					rem--;
					ans += i;
				}
			}
			else if(rem == 1 && !cnt[i]) {
				ans += i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
