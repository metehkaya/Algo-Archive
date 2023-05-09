#include <bits/stdc++.h>
using namespace std;

int T,xa,xb,ya,yb;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
		int cx = abs(xa-xb);
		int cy = abs(ya-yb);
		if(cx == 0 && cy == 0)
			puts("0");
		else if(cx == 0 || cy == 0)
			printf("%d\n",cx+cy);
		else
			printf("%d\n",cx+cy+2);
	}
	return 0;
}
