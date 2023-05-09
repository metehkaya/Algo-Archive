#include <bits/stdc++.h>
#define maxn 300001
using namespace std;

int T,n;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		int mx = ar[1] , ans = -1;
		for( int i = 2 ; i <= n ; i++ )
			mx = max(mx,ar[i]);
		for( int i = 1 ; i <= n && ans == -1 ; i++ )
			if(ar[i] == mx) {
				if(i > 1 && ar[i] > ar[i-1])
					ans = i;
				else if(i < n && ar[i] > ar[i+1])
					ans = i;
			}
		printf("%d\n",ans);
	}
	return 0;
}
