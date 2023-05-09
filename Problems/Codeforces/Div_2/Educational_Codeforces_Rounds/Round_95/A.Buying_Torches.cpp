#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;
LL x,y,k;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%lld%lld%lld",&x,&y,&k);
		LL p = y*k+k-1;
		LL q = x-1;
		if(p%q)
			printf("%lld\n",p/q+1+k);
		else
			printf("%lld\n",p/q+k);
	}
	return 0;
}
