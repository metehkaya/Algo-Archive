#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
LL a,b,ans;

int main() {
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a >> b;
		a--;
		ans += b*(b+1)/2;
		ans -= a*(a+1)/2;
	}
	cout << ans << endl;
	return 0;
}
