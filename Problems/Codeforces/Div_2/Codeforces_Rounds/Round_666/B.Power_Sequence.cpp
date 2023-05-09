#include <bits/stdc++.h>
#define maxn 100003
#define maxs 1000000000000LL
using namespace std;
typedef long long LL;

int T,n;
int ar[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	sort(ar+1,ar+n+1);
	LL ans = (1LL << 60);
	for( int k = 1 ; k <= 1000000 ; k++ ) {
		LL sum = 0;
		LL mult = 1;
		for( int i = 1 ; i <= n ; i++ ) {
			if(mult > maxs) {
				sum = -1;
				break;
			}
			sum += max(ar[i]-mult,mult-ar[i]);
			mult *= k;
		}
		if(sum != -1)
			ans = min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
