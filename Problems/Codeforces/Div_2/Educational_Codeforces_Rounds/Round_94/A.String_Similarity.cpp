#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n >> s;
		for( int i = 0 ; i < n ; i++ )
			printf("%c",s[n-1]);
		puts("");
	}
	return 0;
}
