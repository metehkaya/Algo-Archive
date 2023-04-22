#include <bits/stdc++.h>
using namespace std;

int T,n;
int p[51];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i <= n ; i++ )
			scanf("%d",&p[i]);
		printf("Case #%d: ",tc);
		if(n%2) {
			puts("1");
			puts("0.0");
		}
		else
			puts("0");
	}
	return 0;
}

