#include <bits/stdc++.h>
using namespace std;

int T,n,m,N,M;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&m);
		printf("Case #%d:\n",tc);
		N = 2*n , M = 2*m;
		for( int i = 0 ; i <= N ; i++ , puts("") )
			for( int j = 0 ; j <= M ; j++ ) {
				if(i < 2 && j < 2)
					printf(".");
				else if(i % 2 == 1 && j % 2 == 1)
					printf(".");
				else if((i+j) % 2 == 0)
					printf("+");
				else if(i%2 == 0)
					printf("-");
				else
					printf("|");
			}
	}
	return 0;
}
