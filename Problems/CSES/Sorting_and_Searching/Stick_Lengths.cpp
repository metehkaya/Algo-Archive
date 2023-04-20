#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
typedef long long LL;

int n;
LL ar[maxn];
LL sum[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%lld",&ar[i]);
	sort(ar+1,ar+n+1);
	for( int i = 1 ; i <= n ; i++ )
		sum[i] = sum[i-1] + ar[i];
	int m = (n+1)/2;
	LL ans = 0;
	ans += ar[m] * m - sum[m];
	ans += sum[n] - sum[m] - (n-m) * ar[m];
	printf("%lld\n",ans);
	return 0;
}