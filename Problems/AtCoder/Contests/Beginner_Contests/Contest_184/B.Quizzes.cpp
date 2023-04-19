#include <bits/stdc++.h>
using namespace std;

int n,x;
string s;

int main() {
	cin >> n >> x >> s;
	for( int i = 0 ; i < n ; i++ )
		if(s[i] == 'o')
			x++;
		else
			x = max(x-1,0);
	cout << x << endl;
	return 0;
}
