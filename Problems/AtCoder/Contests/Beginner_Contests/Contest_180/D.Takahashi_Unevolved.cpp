#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL x,y,a,b,ans;

int main() {
	scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
	LL score = 0;
	while(true) {
		LL diff = y-x-1;
		ans = max(ans,score+diff/b);
		if((y-1)/x < a)
			break;
		score++;
		x *= a;
	}
	printf("%lld\n",ans);
	return 0;
}
