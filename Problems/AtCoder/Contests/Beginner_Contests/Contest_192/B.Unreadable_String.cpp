#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
	cin >> s;
	n = s.length();
	for( int i = 0 ; i < n ; i++ )
		if(i%2 == 0 && s[i] >= 'A' && s[i] <= 'Z') {
			cout << "No" << endl;
			return 0;
		}
		else if(i%2 == 1 && s[i] >= 'a' && s[i] <= 'z') {
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
	return 0;
}
