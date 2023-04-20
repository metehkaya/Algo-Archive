#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
typedef long long LL;

LL ans;
int n,a,b;
LL sum[maxn];
multiset<LL> s;

int main() {
	scanf("%d%d%d",&n,&a,&b);
	ans = LLONG_MIN;
	for( int i = 1 , val ; i <= n ; i++ ) {
		scanf("%d",&val);
		sum[i] = sum[i-1] + val;
	}
	for( int i = a ; i <= n ; i++ ) {
		s.insert(sum[i-a]);
		if(i > b) {
			auto it = s.find(sum[i-b-1]);
			s.erase(it);
		}
		auto it = s.begin();
		ans = max( ans , sum[i] - (*it) );
	}
	printf("%lld\n",ans);
	return 0;
}