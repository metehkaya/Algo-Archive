#include <bits/stdc++.h>
#define maxn 1000
using namespace std;
typedef long long LL;

int T,n,k;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		LL sum1 = 0 , sum2 = 0;
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&ar[i]);
			sum1 += ar[i];
			sum2 += ar[i]*ar[i];
		}
		LL p = sum2 - sum1*sum1;
		LL q = 2*sum1;
		if(q != 0) {
			LL abs_p = max(p,-p);
			LL abs_q = max(q,-q);
			if(abs_p % abs_q)
				printf("Case #%d: IMPOSSIBLE\n",tc);
			else
				printf("Case #%d: %lld\n",tc,p/q);
		}
		else {
			if(p != 0)
				printf("Case #%d: IMPOSSIBLE\n",tc);
			else
				printf("Case #%d: 0\n",tc);
		}
	}
	return 0;
}
