#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
typedef long long LL;

struct item {
	int p,r;
}ar[maxn];

bool comp(const item &a , const item &b) {
	return (double) a.r / a.p < (double) b.r / b.p;
}

int n,g,rem;
LL ans;
LL add[maxn];

LL gcd(LL x , LL y) {
	if(!y)
		return x;
	return gcd(y,x%y);
}

int main() {
	scanf("%d%d",&n,&g);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d%d",&ar[i].p,&ar[i].r);
	sort(ar,ar+n,comp);
	rem = g;
	LL temp = 0;
	for( int i = 0 ; i < n ; i++ ) {
		rem -= ar[i].r;
		add[i] = (LL) ar[i].p * rem;
		temp += add[i];
	}
	for( int i = n-1 , sum = 0 ; i >= 0 ; i-- ) {
		LL val = temp - add[i] + (LL) ar[i].r * sum + (LL) (rem + ar[i].r) * ar[i].p;
		ans = max(ans,val);
		sum += ar[i].p;
	}
	LL gc = gcd(ans,n);
	printf("%lld %lld\n",ans/gc,n/gc);
	return 0;
}
