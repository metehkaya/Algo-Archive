#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T,n;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		int ans = 0, curr = 0, sum = 0, best = INT_MIN;
		for( int i = 0 , x ; i < n ; i++ ) {
			scanf("%d",&x);
			best = max(best, x);
			if(x>0)
				sum += x;
			curr = max(curr+x, 0);
			ans = max(ans, curr);
		}
		if(best < 0)
			printf("%d %d\n", best, best);
		else
			printf("%d %d\n", ans, sum);
	}
	return 0;
}
