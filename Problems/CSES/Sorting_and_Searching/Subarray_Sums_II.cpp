#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
LL x,ans;
map<LL,int> cnt;

int main() {
	scanf("%d%lld",&n,&x);
	cnt[0] = 1;
	for( LL i = 0 , sum = 0 , val ; i < n ; i++ ) {
		scanf("%lld",&val);
		sum += val;
		auto it = cnt.find(sum-x);
		if(it != cnt.end())
			ans += it->second;
		cnt[sum]++;
	}
	printf("%lld\n",ans);
	return 0;
}