#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;
int cnt[2];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cnt[0] = cnt[1] = 0;
		scanf("%d",&n);
		cin >> s;
		for( int i = 0 ; i < n ; i++ )
			cnt[i%2] += (s[i]-'0')%2;
		if(n%2 == 0) {
			if(cnt[1] < n/2)
				puts("2");
			else
				puts("1");
		}
		else {
			if(cnt[0])
				puts("1");
			else
				puts("2");
		}
	}
	return 0;
}
