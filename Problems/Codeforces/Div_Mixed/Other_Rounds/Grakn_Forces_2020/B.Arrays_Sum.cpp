#include <bits/stdc++.h>
#define maxn 101
using namespace std;

int T,n,k;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		if(k == 1) {
			if(ar[1] != ar[n])
				puts("-1");
			else
				puts("1");
		}
		else {
			int diff = 0;
			for( int i = 1 ; i < n ; i++ )
				diff += (ar[i] != ar[i+1]);
			printf("%d\n",max(diff/(k-1) + !!(diff%(k-1)),1));
		}
	}
	return 0;
}
