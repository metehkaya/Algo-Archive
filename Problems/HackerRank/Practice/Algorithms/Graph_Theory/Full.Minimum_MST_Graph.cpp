#include <bits/stdc++.h>
using	 namespace std;
typedef  long long LL;

LL g,n,m,s;

int main() {
	scanf("%lld",&g);
	while(g--) {
		scanf("%lld%lld%lld",&n,&m,&s);
		LL diff = m - (n-1);
		LL comb = (n-1)*(n-2)/2 - (n-2);
		if(diff <= comb)
			printf("%lld\n",s+diff);
		else {
			LL edge = s - (n-2);
			LL p = m - (n-1)*(n-2)/2;
			if( (n-1) / 2.0 >= (double) p )
				printf("%lld\n",(n-1)*(n-2)/2+p*edge);
			else {
				LL diff = edge - 1;
				LL times = diff / (n-1);
				LL edge1 = 1 + times;
				LL edge2 = edge - times * (n-2);
				LL res = edge1 * (n-1) * (n-2) / 2 + p * edge2;
				LL rem = diff % (n-1);
				if(rem < 2)
					printf("%lld\n",res);
				else {
					double avg = ( (n-2) + (n-2 - rem + 2) ) / 2.0;
					if( avg >= (double) p )
						printf("%lld\n",res);
					else
						printf("%lld\n",res-p*(rem-1)+(rem-1)*((n-2)+(n-2-rem+2))/2);
				}
			}
		}
	}
	return 0;
}
