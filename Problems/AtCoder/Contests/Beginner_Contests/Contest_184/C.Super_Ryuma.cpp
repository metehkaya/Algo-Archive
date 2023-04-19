#include <bits/stdc++.h>
using namespace std;

int r1,c1,r2,c2;

int main() {
	cin >> r1 >> c1 >> r2 >> c2;
	if(r1 == r2 && c1 == c2)
		puts("0");
	else {
		if(r1+c1 == r2+c2)
			puts("1");
		else if(r1-c1 == r2-c2)
			puts("1");
		else if(abs(r1-r2)+abs(c1-c2) <= 3)
			puts("1");
		else {
			if((abs(r1-r2)+abs(c1-c2))%2 == 0)
				puts("2");
			else {
				int ans = 3;
				for( int i = -2 ; i <= 2 ; i++ )
					for( int j = -2 ; j <= 2 ; j++ ) {
						if(r1+c1 == r2+i+c2+j)
							ans = 2;
						if(r1-c1 == r2+i-c2-j)
							ans = 2;
					}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
