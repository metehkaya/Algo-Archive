#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T,n;
LL m,ans;
set<LL>sumset;
set<LL>::iterator it;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		ans = 0;
		sumset.clear();
		scanf("%d%lld",&n,&m);
		sumset.insert(0);
		LL x , sum = 0;
		for( int i = 1 ; i <= n ; i++ ) {
			scanf("%lld",&x);
			sum = (sum + (x%m)) % m;
			it = sumset.upper_bound(sum);
			ans = max(ans,sum);
			if(it != sumset.end())
				ans = max(ans,m+sum-(*it));
			sumset.insert(sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
