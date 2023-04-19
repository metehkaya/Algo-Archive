#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;

LL n;
vector<LL> ans;

int main() {
	scanf("%lld",&n);
	for( LL i = 1 ; i*i <= n ; i++ )
		if(n%i == 0) {
			ans.pb(i);
			if(i*i != n)
				ans.pb(n/i);
		}
	sort(ans.begin(),ans.end());
	for( int i = 0 ; i < ans.size() ; i++ )
		printf("%lld\n",ans[i]);
	return 0;
}
