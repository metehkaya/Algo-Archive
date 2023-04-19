#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	int len = s.length();
	if(s[len-1] == 's')
		s += "es";
	else
		s += "s";
	cout << s << endl;
	return 0;
}
