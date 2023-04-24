#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T,n,m,k;
int r1,c1,r2,c2;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		LL ans = min( min(r1-1,c1-1) , min(n-r2,m-c2) );
		LL nr = r2-r1+1 , nc = c2-c1+1;
		ans += nr*(nc+1) + (nr+1)*nc;
		if(r1 == 1)
			ans -= c2-c1+1;
		if(r2 == n)
			ans -= c2-c1+1;
		if(c1 == 1)
			ans -= r2-r1+1;
		if(c2 == m)
			ans -= r2-r1+1;
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
