#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n;
int T;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%lld",&n);
		int res = 0;
		LL sum = 0;
		for( LL x = 1 ; true ; x = 2*(x+1)-1 ) {
			sum += x*(x+1)/2;
			if(sum > n)
				break;
			res++;
		}
		printf("%lld\n",res);
	}
	return 0;
}
