#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
typedef long double ld;

int n,m,k;
int forbs[10];
bool forb[maxn];
ld sumf[maxn];
ld sumc[maxn];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 0 ; i < k ; i++ ) {
		scanf("%d",&forbs[i]);
		forb[forbs[i]] = true;
		if(i >= m-1 && forbs[i]-forbs[i-(m-1)] == m-1) {
			puts("-1");
			return 0;
		}
	}
	for( int i = n-1 ; i >= 1 ; i-- ) {
		ld f,c;
		if(forb[i])
			f = 1 , c = 0;
		else {
			f = sumf[i+1] - sumf[i+m+1];
			c = sumc[i+1] - sumc[i+m+1];
			f /= m , c /= m;
			c += 1;
		}
		sumf[i] = sumf[i+1] + f;
		sumc[i] = sumc[i+1] + c;
	}
	ld f = sumf[1] - sumf[m+1];
	ld c = sumc[1] - sumc[m+1];
	f /= m , c /= m;
	c += 1;
	double C = c;
	double F = f;
	printf("%lf\n",C/(1-F));
	return 0;
}
