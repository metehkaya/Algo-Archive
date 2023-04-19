#include <bits/stdc++.h>
using namespace std;

string s,t;

int main() {
	cin >> s >> t;
	int a = s[0]-'0' + s[1]-'0' + s[2]-'0';
	int b = t[0]-'0' + t[1]-'0' + t[2]-'0';
	printf("%d\n",max(a,b));
	return 0;
}
