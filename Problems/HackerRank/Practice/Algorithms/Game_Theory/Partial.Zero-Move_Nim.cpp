#include <bits/stdc++.h>
using namespace std;

int T,n;

int main() {
	scanf("%d",&T);
	for( int tc = 1 , val ; tc <= T ; tc++ ) {
		val = 0;
		scanf("%d",&n);
		for( int i = 0 , x ; i < n ; i++ ) {
			scanf("%d",&x);
			val ^= x;
		}
		if(val)
			puts("W");
		else
			puts("L");
	}
	return 0;
}
