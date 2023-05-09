#include <bits/stdc++.h>
#define maxn 1001
using namespace std;
typedef long long LL;

int T,n;
int x[maxn];
int y[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d%d",&x[i],&y[i]);
		if(n&1)
			puts("1");
		else {
			sort(x+1,x+n+1);
			sort(y+1,y+n+1);
			LL X = x[n/2+1]-x[n/2]+1;
			LL Y = y[n/2+1]-y[n/2]+1;
			printf("%lld\n",X*Y);
		}
	}
	return 0;
}
