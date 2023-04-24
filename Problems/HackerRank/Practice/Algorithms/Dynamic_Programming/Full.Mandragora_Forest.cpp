#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
typedef long long LL;

int T,n;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		LL sum=0;
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&ar[i]);
			sum += ar[i];
		}
		sort(ar, ar+n);
		LL h=1, ans=sum;
		for( int i = 0 ; i < n ; i++ ) {
			h++;
			sum -= ar[i];
			ans = max(ans, h*sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
