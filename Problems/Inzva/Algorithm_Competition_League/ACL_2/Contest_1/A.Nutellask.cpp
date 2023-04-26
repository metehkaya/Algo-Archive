#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
typedef long long LL;

int n;
int ar[maxn];
LL sum[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		sum[i] = sum[i-1] + ar[i];
	}
	LL ans = abs(sum[n]-2*ar[1]);
	for( int i = 2 ; i < n ; i++ ) {
		LL diff = abs(sum[n]-2*sum[i]);
		ans = min(ans,diff);
	}
	printf("%lld\n",ans);
	return 0;
}