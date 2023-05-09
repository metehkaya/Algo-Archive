#include <bits/stdc++.h>
#define maxn 50003
using namespace std;

int T,n;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		int cnt = 0;
		for( int i = 2 ; i <= n ; i++ )
			cnt += (ar[i-1] > ar[i]);
		if(cnt == n-1)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}
