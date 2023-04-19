#include <bits/stdc++.h>
using namespace std;

int n,ans;

int f(int x , int b) {
	while(x) {
		if(x % b == 7)
			return false;
		x /= b;
	}
	return true;
}

int main() {
	cin >> n;
	for( int i = 1 ; i <= n ; i++ )
		ans += (f(i,8) && f(i,10));
	cout << ans << endl;
	return 0;
}
