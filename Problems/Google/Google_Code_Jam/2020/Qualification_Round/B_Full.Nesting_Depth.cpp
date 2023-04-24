#include <bits/stdc++.h>
#define maxn 103
using namespace std;

int T,n;
char s[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%s",s);
		printf("Case #%d: ",tc);
		n = strlen(s);
		int curr = 0;
		for( int i = 0 ; i < n ; i++ ) {
			int val = s[i] - '0';
			while(curr < val) {
				curr++;
				printf("(");
			}
			while(curr > val) {
				curr--;
				printf(")");
			}
			printf("%c",s[i]);
		}
		while(curr > 0) {
			curr--;
			printf(")");
		}
		puts("");
	}
	return 0;
}
