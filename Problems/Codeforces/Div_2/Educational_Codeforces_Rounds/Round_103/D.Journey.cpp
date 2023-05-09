#include <bits/stdc++.h>
#define maxn 300005
using namespace std;

int T,n;
int l[maxn];
int r[maxn];
char s[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%s",&n,s+1);
		n++;
		for( int i = 1 , j = 1 ; i < n ; i = j ) {
			while(j < n) {
				int diff = j-i;
				if(diff % 2 == 0 && s[i] == s[j])
					j++;
				else if(diff % 2 == 1 && s[i] != s[j])
					j++;
				else
					break;
			}
			for( int k = i ; k < j ; k++ ) {
				l[k] = i;
				r[k] = j-1;
			}
		}
		for( int i = 1 ; i <= n ; i++ ) {
			int res = 1;
			if(i > 1 && s[i-1] == 'L')
				res += (i-1) - l[i-1] + 1;
			if(i < n && s[i] == 'R')
				res += r[i] - i + 1;
			printf("%d ",res);
		}
		puts("");
	}
	return 0;
}
