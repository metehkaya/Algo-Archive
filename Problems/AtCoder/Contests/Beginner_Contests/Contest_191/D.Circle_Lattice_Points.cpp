#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double ld;

LL ans;
ld cx,cy,rr;
ld EPS = 1e-9;

void bs2(int l , int r , int y) {
	int p = l;
	int last = INT_MIN;
	while(l <= r) {
		int m = (l+r)/2;
		ld d = (m-cx)*(m-cx) + (y-cy)*(y-cy);
		if(d <= rr*rr+EPS)
			last = m , l = m+1;
		else
			r = m-1;
	}
	if(last != INT_MIN)
		ans += last-p+1;
}

void bs1(int l , int r , int y) {
	int p = r;
	int last = INT_MIN;
	while(l <= r) {
		int m = (l+r)/2;
		ld d = (m-cx)*(m-cx) + (y-cy)*(y-cy);
		if(d <= rr*rr+EPS)
			last = m , r = m-1;
		else
			l = m+1;
	}
	if(last != INT_MIN)
		ans += p-last+1;
}

int main() {
	cin >> cx >> cy >> rr;
	for( int y = cy-rr-3 ; y <= cy+rr+3 ; y++ ) {
		int l,r;
		if(cx >= 0)
			r = cx;
		else {
			r = cx;
			if(r != cx)
				r--;
		}
		l = r-rr-3;
		bs1(l,r,y);
		l = r+1;
		r = l+rr+3;
		bs2(l,r,y);
	}
	printf("%lld\n",ans);
	return 0;
}
