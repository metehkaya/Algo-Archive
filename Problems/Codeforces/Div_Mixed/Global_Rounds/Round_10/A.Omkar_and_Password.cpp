#include <bits/stdc++.h>
#define maxn 200000
using namespace std;

int T,n;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&ar[i]);
		sort(ar,ar+n);
		if(ar[0] == ar[n-1])
			printf("%d\n",n);
		else
			puts("1");
	}
	return 0;
}
