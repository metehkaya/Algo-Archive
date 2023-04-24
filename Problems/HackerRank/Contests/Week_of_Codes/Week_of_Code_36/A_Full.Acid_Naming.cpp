#include <bits/stdc++.h>
#define maxn 10003
using namespace std;

int T,n;
char s[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%s",s);
		n = strlen(s);
		if(s[n-2] == 'i' && s[n-1] == 'c') {
			if(n >= 7 && s[0] == 'h' && s[1] == 'y' && s[2] == 'd' && s[3] == 'r' && s[4] == 'o')
				puts("non-metal acid");
			else
				puts("polyatomic acid");
		}
		else
			puts("not an acid");
	}
	return 0;
}
