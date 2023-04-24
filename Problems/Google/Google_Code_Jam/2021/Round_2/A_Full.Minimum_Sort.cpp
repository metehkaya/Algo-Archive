#include <bits/stdc++.h>
using namespace std;

int T,n;

int main() {
	scanf("%d%d",&T,&n);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		int ok;
		for( int i = 1 ; i < n ; i++ ) {
			cout << "M " << i << " " << n << endl;
			fflush(stdout);
			int idx;
			cin >> idx;
			if(i != idx) {
				cout << "S " << i << " " << idx << endl;
				fflush(stdout);
				cin >> ok;
			}
		}
		cout << "D" << endl;
		fflush(stdout);
		cin >> ok;
	}
	return 0;
}
