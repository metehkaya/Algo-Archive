#include <bits/stdc++.h>
#define maxn 1001
#define pb push_back
using namespace std;

int n;
vector<int> v[maxn];

int conv(string inp) {
	int val = 0;
	int len = inp.length();
	for( int i = 0 ; i < len ; i++ ) {
		val *= 10;
		val += inp[i] - '0';
	}
	return val;
}

void readInput(int i) {
	string inp1,inp2;
	cin >> inp1;
	if( inp1.compare("MATCH") != 0 ) {
		cin >> inp2;
		int x = conv(inp1);
		int y = conv(inp2);
		v[x].pb(i);
		v[y].pb(i+n);
	}
}

int main() {
	cin >> n;
	for( int i = 1 ; i <= n ; i++ ) {
		cout << i << " " << i+n << "\n";
		cout.flush();
		readInput(i);
	}
	for( int i = 1 ; i <= n ; i++ )
		if( v[i].size() ) {
			string inp;
			int x = v[i][0] , y = v[i][1];
			if(x>y)
				swap(x,y);
			cout << x << " " << y << "\n";
			cout.flush();
			cin >> inp;
		}
	cout << "-1" << "\n";
	cout.flush();
	return 0;
}
