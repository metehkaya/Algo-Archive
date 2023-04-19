#include <bits/stdc++.h>
#define maxn 100
using namespace std;

int n,m,mn,ans;
int ar[maxn][maxn];

int main() {
	mn = INT_MAX;
	cin >> n >> m;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ ) {
			cin >> ar[i][j];
			mn = min(mn,ar[i][j]);
		}
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			ans += ar[i][j] - mn;
	cout << ans << endl;
	return 0;
}
