#include <bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long LL;

int n,k;
int ar[maxn];

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	sort(ar,ar+n);
	LL l = 1 , r = (LL) k*ar[0] , ans;
	while(l <= r) {
		LL m = (l+r) >> 1;
		LL cnt = 0;
		for( int i = 0 ; i < n ; i++ )
			cnt += m / ar[i];
		if(cnt >= k)
			ans = m , r = m-1;
		else
			l = m+1;
	}
	printf("%lld\n",ans);
	return 0;
}