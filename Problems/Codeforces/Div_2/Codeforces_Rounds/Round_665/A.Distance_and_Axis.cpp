#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int T,n,k;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		if(n < k)
			printf("%d\n",k-n);
		else
			printf("%d\n",(n&1)!=(k&1));
	}
	return 0;
}
