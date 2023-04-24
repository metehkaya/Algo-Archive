#include <bits/stdc++.h>
using namespace std;

int T,a,b,c;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",a+b-c);
	}
	return 0;
}
