#include <bits/stdc++.h>
#define maxn 100
using namespace std;

int T,n;
int a[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&a[i]);
		int cnt = 0;
		for( int i = 1 ; i < n-1 ; i++ )
			if( a[i] > max( a[i-1] , a[i+1] ) )
				cnt++;
		printf("Case #%d: %d\n",tc,cnt);
	}
	return 0;
}
