#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	if(s[0] == s[1] && s[1] == s[2])
		cout << "Won" << endl;
	else
		cout << "Lost" << endl;
	return 0;
}
