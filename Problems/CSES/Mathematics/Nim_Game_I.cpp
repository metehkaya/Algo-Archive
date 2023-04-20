#include <bits/stdc++.h>
using namespace std;

int T,n;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		int xo = 0;
		scanf("%d",&n);
		for( int i = 0 , val ; i < n ; i++ ) {
			scanf("%d",&val);
			xo ^= val;
		}
		if(xo)
			puts("first");
		else
			puts("second");
	}
	return 0;
}