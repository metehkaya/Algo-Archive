#include <bits/stdc++.h>
#define maxn 101
using namespace std;

int T,n,c;
int ar[maxn];
int ans[maxn];
int cost[maxn];

void rev(int l , int r) {
	int len = r-l+1;
	for( int i = 0 ; i < len/2 ; i++ )
		swap(ar[l+i],ar[r-i]);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&c);
		if(c < n-1 || c >= n*(n+1)/2)
			printf("Case #%d: IMPOSSIBLE\n",tc);
		else {
			c -= n-1;
			for( int i = 1 ; i < n ; i++ )
				cost[i] = 1;
			for( int i = 1 ; i < n && c > 0 ; i++ ) {
				int rem = min(c,n-i);
				c -= rem;
				cost[i] += rem;
			}
			for( int i = 1 ; i <= n ; i++ )
				ar[i] = i;
			for( int i = 1 ; i < n ; i++ ) {
				int idx = i+cost[i]-1;
				ans[ar[idx]] = i;
				if(i == n-1)
					ans[ar[2*n-1-idx]] = n;
				rev(i,idx);
			}
			printf("Case #%d:",tc);
			for( int i = 1 ; i <= n ; i++ )
				printf(" %d",ans[i]);
			puts("");
		}
	}
	return 0;
}
