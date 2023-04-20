#include <bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long LL;

const LL MAXV = (LL) 1e9;

int n;
LL ans;
int cnt[maxn];

int main() {
	scanf("%d",&n);
	cnt[0] = 1;
	for( LL i = 0 , sum = n*MAXV , val ; i < n ; i++ ) {
		scanf("%lld",&val);
		sum += val;
		ans += cnt[sum%n];
		cnt[sum%n]++;
	}
	printf("%lld\n",ans);
	return 0;
}