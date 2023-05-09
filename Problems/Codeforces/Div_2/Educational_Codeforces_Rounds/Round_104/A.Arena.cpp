#include <bits/stdc++.h>
using namespace std;

int T,n;
int ar[100];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		int mn = INT_MAX;
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&ar[i]);
			mn = min(mn,ar[i]);
		}
		int ans = 0;
		for( int i = 0 ; i < n ; i++ )
			ans += (ar[i] > mn);
		printf("%d\n",ans);
	}
	return 0;
}
