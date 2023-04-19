#include <bits/stdc++.h>
#define maxn 401
using namespace std;
typedef long long LL;

int n;
LL ans;
int cnt[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		x += 200;
		for( int y = 0 ; y < maxn ; y++ )
			ans += (LL) cnt[y]*(x-y)*(x-y);
		cnt[x]++;
	}
	printf("%lld\n",ans);
	return 0;
}
