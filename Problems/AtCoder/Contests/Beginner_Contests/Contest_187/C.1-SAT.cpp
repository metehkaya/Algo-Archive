#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
string ans;
map<string,int> mp;

int main() {
	ans = "satisfiable";
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		string s;
		cin >> s;
		if(s[0] != '!')
			mp[s] |= 1;
		else {
			s = s.substr(1,s.length()-1);
			mp[s] |= 2;
		}
		if(mp[s] == 3)
			ans = s;
	}
	cout << ans << endl;
	return 0;
}
