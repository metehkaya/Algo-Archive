#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int cnt[10];

int main() {
	cin >> s;
	n = s.length();
	for( int i = 0 ; i < n ; i++ )
		cnt[s[i]-'0']++;
	for( int i = 8 ; i < 1000 ; i += 8 ) {
		if(i <= 9 && n != 1)
			continue;
		if(i >= 10 && i <= 99 && n != 2)
			continue;
		if(i >= 100 && i <= 999 && n < 3)
			continue;
		vector<int> temp(10,0);
		int x = i;
		while(x) {
			temp[x%10]++;
			x /= 10;
		}
		bool ok = true;
		for( int j = 0 ; j < 10 ; j++ )
			if(temp[j] > cnt[j]) {
				ok = false;
				break;
			}
		if(ok) {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}
