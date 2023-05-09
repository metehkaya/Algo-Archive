#include <bits/stdc++.h>
using namespace std;

int T,n;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		int dig = n%10 , cnt = 0;
		while(n) {
			cnt++;
			n /= 10;
		}
		printf("%d\n",10*(dig-1)+cnt*(cnt+1)/2);
	}
	return 0;
}
