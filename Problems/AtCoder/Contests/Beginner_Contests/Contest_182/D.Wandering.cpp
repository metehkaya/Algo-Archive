#include <bits/stdc++.h>
#define maxn 200003
using namespace std;
typedef long long LL;

int n;
int ar[maxn];
LL mx[maxn];
LL sum[maxn];
LL total[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		sum[i] = sum[i-1]+ar[i];
		mx[i] = max(mx[i-1],sum[i]);
		total[i] = total[i-1]+sum[i];
	}
	LL ans = 0;
	for( int i = 1 ; i <= n ; i++ ) {
		LL curr = total[i-1];
		curr += mx[i];
		ans = max(ans,curr);
	}
	printf("%lld\n",ans);
	return 0;
}
