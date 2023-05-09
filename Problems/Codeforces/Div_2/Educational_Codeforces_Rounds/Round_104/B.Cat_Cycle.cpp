#include <bits/stdc++.h>
using namespace std;

int T,n,k;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		k--;
		if(n%2 == 0) {
			int x = k%n;
			printf("%d\n",++x);
		}
		else {
			int c = n/2;
			int x = (k+k/c)%n;
			printf("%d\n",++x);
		}
	}
	return 0;
}
