#include <bits/stdc++.h>
using namespace std;

int T,n;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		if(n == 1 || n == 2 || n == 4)
			puts("-1");
		else if(n%3 == 0)
			printf("%d 0 0\n",n/3);
		else if((n-5)%3 == 0)
			printf("%d 1 0\n",(n-5)/3);
		else
			printf("%d 0 1\n",(n-7)/3);
	}
	return 0;
}
