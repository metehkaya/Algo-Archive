#include <bits/stdc++.h>
#define maxn 1000000
using namespace std;
typedef long long LL;

int n;
LL sum;
LL ar[maxn];

LL total(LL x) {
	LL y = x+n-1;
	LL tot = (x+y)*n/2;
	return tot;
}

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		scanf("%lld",&ar[i]);
		sum += ar[i];
	}
	LL l = 0 , r = (1LL << 40) , last = -1;
	while(l <= r) {
		LL mid = (l+r) >> 1;
		if(total(mid) <= sum)
			last = mid , l = mid+1;
		else
			r = mid-1;
	}
	for( int i = 0 ; i < n ; i++ ) {
		ar[i] = last+i;
		sum -= ar[i];
	}
	for( int i = 0 ; i < n ; i++ )
		if(sum) {
			sum--;
			ar[i]++;
		}
	for( int i = 0 ; i < n ; i++ )
		printf("%lld ",ar[i]);
	return 0;
}
