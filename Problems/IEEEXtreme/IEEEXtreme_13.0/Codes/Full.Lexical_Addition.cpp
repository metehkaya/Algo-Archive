#include <bits/stdc++.h>
#define maxd 100000
using namespace std;
typedef long long LL;

LL n,a,b;
LL ans[maxd];

int main() {
	scanf("%lld%lld%lld",&n,&a,&b);
	if(a>b)
		swap(a,b);
	int dig = n/b;
	if(n%b)
		dig++;
	if(dig*a > n || dig > maxd)
		puts("NO");
	else {
		puts("YES");
		LL dif = b-a;
		if( dif == 0 ) {
			for( int j = dig-1 ; j >= 0 ; j-- )
				printf("%lld ", b);
		}
		else {
			n -= dig*a;
			LL divv = n/dif;
			LL rem = n%dif;
			for( int j = 0 ; j < divv ; j++ )
				ans[j] = dif;
			if(rem)
				ans[divv] = rem;
			for( int j = dig-1 ; j >= 0 ; j-- )
				printf("%lld ", a+ans[j]);
		}
	}
	return 0;
}
