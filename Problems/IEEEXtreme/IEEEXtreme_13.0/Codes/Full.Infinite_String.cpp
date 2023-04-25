#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL m;
int T,n;
LL pwr[61];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%lld",&n,&m);
		if(n==1) {
			puts("a");
			continue;
		}
		pwr[0] = 1;
		for( int i = 1 ; pwr[i-1] != -1 ; i++ ) {
			if(pwr[i-1]>m/n)
				pwr[i] = -1;
			else
				pwr[i] = pwr[i-1]*n;
		}
		LL sum = 0;
		int nDig = 0;
		for( int i = 1 ; !nDig ; i++ ) {
			if( pwr[i] == -1 || pwr[i] > (m-sum) / i || sum + pwr[i]*i > m )
				nDig = i;
			else
				sum += pwr[i]*i;
		}
		LL rem = m-sum;
		LL w0 = rem/nDig;
		LL w1 = rem%nDig;
		int digs[nDig];
		for( int i = nDig-1 ; i >= 0 ; i-- ) {
			digs[nDig-1-i] = w0 / pwr[i];
			w0 -= digs[nDig-1-i] * pwr[i];
		}
		printf("%c\n",'a'+digs[w1]);
	}
	return 0;
}
