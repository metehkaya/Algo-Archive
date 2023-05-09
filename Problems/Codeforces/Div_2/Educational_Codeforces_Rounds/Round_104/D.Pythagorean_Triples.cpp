#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T,n;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		int l = 1 , r = 100000 , ans = 0;
		while(l <= r) {
			int mid = (l+r) >> 1;
			LL a = 1 + 2*mid;
			LL b = a*a/2;
			LL c = b+1;
			if(c <= (LL)n) {
				ans = mid;
				l = mid+1;
			}
			else
				r = mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
