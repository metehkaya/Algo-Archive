#include <bits/stdc++.h>
using namespace std;

int T;
int digits[8];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		string s;
		cin >> s;
		int len = s.length();
		memset(digits,0,sizeof(digits));
		for( int i = 0 ; i < len ; i++ )
			digits[i] = s[i]-'0';
		sort(digits,digits+len);
		int ans = INT_MAX;
		do {
			if(digits[0] == 0)
				continue;
			int x = 0;
			for( int i = 1 ; i < len ; i++ ) {
				x = 10*x + digits[i-1];
				if(digits[i] != 0) {
					int y = 0;
					for( int j = i ; j < len ; j++ )
						y = 10*y + digits[j];
					ans = min(ans,abs(x-y));
				}
			}
		}while(next_permutation(digits,digits+len));
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
