#include <bits/stdc++.h>
using namespace std;

int T,n,k;
string s;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n >> k >> s;
		int val = 0;
		for( int i = 0 ; i < n/2 ; i++ )
			val += s[i] != s[n-1-i];
		printf("Case #%d: %d\n",tc,abs(k-val));
	}
	return 0;
}
