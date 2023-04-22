#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T,n,k;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		vector<LL> v;
		v.push_back(0);
		LL ans = 0 , sum = 0;
		for( int i = 1 , x ; i <= n ; i++ ) {
			scanf("%d",&x);
			sum += x;
			int add = i - (lower_bound(v.begin(),v.end(),sum-k) - v.begin());
			ans += add;
			v.push_back(sum);
		}
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
