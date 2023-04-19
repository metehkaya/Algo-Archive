#include <bits/stdc++.h>
using namespace std;

int n,sum;
string s;

int main() {
	cin >> s;
	n = s.length();
	for( int i = 0 ; i < n ; i++ )
		sum += s[i]-'0';
	if(sum%9)
		puts("No");
	else
		puts("Yes");
	return 0;
}
