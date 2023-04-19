#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL ans;
LL a,b,c,d;

int main() {
	ans = -(1LL<<60);
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	if(a <= 0 && b >= 0)
		ans = 0;
	else if(c <= 0 && d >= 0)
		ans = 0;
	ans = max(ans,a*c);
	ans = max(ans,a*d);
	ans = max(ans,b*c);
	ans = max(ans,b*d);
	printf("%lld\n",ans);
	return 0;
}
