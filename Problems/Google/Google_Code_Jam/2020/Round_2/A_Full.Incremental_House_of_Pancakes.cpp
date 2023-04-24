#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;
LL a,b;

LL bs(LL diff) {
	LL l = 1 , r = 2e9 , last = 0;
	while(l <= r) {
		LL mid = (l+r) >> 1;
		LL sq = mid*(mid+1)/2;
		if(sq >= diff)
			last = mid , r = mid-1;
		else
			l = mid+1;
	}
	return last;
}

LL bs(LL x, bool isLeftBigger) {
	LL l = 1 , r = 2e9 , last = 0;
	LL lastA = a, lastB = b;
	while(l <= r) {
		LL mid = (l+r) >> 1;
		LL leftCnt = (mid+1)/2;
		LL rightCnt = mid/2;
		LL leftMin = x+1;
		LL leftMax = x+2*leftCnt-1;
		LL rightMin = x+2;
		LL rightMax = x+2*rightCnt;
		LL leftTotal = (leftMin + leftMax) * leftCnt / 2;
		LL rightTotal = (rightMin + rightMax) * rightCnt / 2;
		if(!isLeftBigger)
			swap(leftTotal, rightTotal);
		if(a >= leftTotal && b >= rightTotal)
			last = mid , l = mid+1 , lastA = a-leftTotal , lastB = b-rightTotal;
		else
			r = mid-1;
	}
	a = lastA;
	b = lastB;
	return last;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%lld%lld",&a,&b);
		LL diff = max(a-b, b-a);
		LL x = bs(diff);
		if(x*(x+1)/2 > max(a,b))
			x--;
		if(a >= b)
			a -= x*(x+1)/2;
		else
			b -= x*(x+1)/2;
		LL y = bs(x, a>=b);
		printf("Case #%d: %lld %lld %lld\n",tc,x+y,a,b);
	}
	return 0;
}
