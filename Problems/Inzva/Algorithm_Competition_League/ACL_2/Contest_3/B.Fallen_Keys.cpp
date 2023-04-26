#include <bits/stdc++.h>
#define maxn 101
using namespace std;

int n,m;
int bm[26];
char s[maxn];
char t[maxn];

int main() {
	scanf("%d%s%d%s",&n,s,&m,t);
	for( int i = 0 ; i < n ; i++ ) {
		int c = s[i]-'a';
		bm[c] |= 1;
	}
	for( int i = 0 ; i < m ; i++ ) {
		int c = t[i]-'a';
		bm[c] |= 2;
	}
	int c0 = 0 , c3 = 0;
	for( int i = 0 ; i < 26 ; i++ )
		if(bm[i] == 0)
			c0++;
		else if(bm[i] == 3)
			c3++;
	if(c3 <= c0)
		printf("%d\n",c3);
	else
		puts("-1");
	return 0;
}
