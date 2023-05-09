#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n >> s;
		int cnt = 0 , len = n;
		while(len && s[0] == s[len-1]) {
			cnt++;
			len--;
		}
		if(!len) {
			if(n <= 2)
				puts("0");
			else
				printf("%d\n",(n+2)/3);
		}
		else {
			int ans = 0;
			s.push_back('-');
			for( int i = 0 ; i < len ; i++ ) {
				cnt++;
				if(s[i] != s[i+1]) {
					ans += cnt/3;
					cnt = 0;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
