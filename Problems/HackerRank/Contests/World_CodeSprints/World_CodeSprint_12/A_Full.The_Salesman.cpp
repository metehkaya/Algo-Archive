#include <bits/stdc++.h>
using namespace std;

int T,n;
int ar[50];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&ar[i]);
		sort(ar,ar+n);
		printf("%d\n",ar[n-1]-ar[0]);
	}
	return 0;
}
