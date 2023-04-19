#include <bits/stdc++.h>
using namespace std;

string s;
int n,sum;
int cnt[3];

int main() {
	cin >> s;
	n = s.length();
	for( int i = 0 ; i < n ; i++ ) {
		int dig = (s[i]-'0')%3;
		sum = (sum + dig) % 3;
		cnt[dig]++;
	}
	if(sum == 0)
		puts("0");
	else if(sum == 1) {
		if(cnt[1] && n > 1)
			puts("1");
		else if(cnt[2] >= 2 && n > 2)
			puts("2");
		else
			puts("-1");
	}
	else {
		if(cnt[2] && n > 1)
			puts("1");
		else if(cnt[1] >= 1 && n > 2)
			puts("2");
		else
			puts("-1");
	}
	return 0;
}
