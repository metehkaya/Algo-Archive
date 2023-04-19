#include <bits/stdc++.h>
using namespace std;

int n,m,t;

int main() {
	scanf("%d%d%d",&m,&n,&t);
	int tt = 0 , curr = m;
	for( int i = 0 , a,b ; i < n ; i++ ) {
		scanf("%d%d",&a,&b);
		curr -= a-tt;
		if(curr <= 0) {
			puts("No");
			return 0;
		}
		curr = min(m,curr+b-a);
		tt = b;
	}
	curr -= t-tt;
	if(curr <= 0) {
		puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}
