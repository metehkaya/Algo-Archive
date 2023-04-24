#include <bits/stdc++.h>
#define maxn 101
using namespace std;

int T,n,ans;
int ar[maxn];

void rev(int l , int r) {
	int len = r-l+1;
	for( int i = 0 ; i < len/2 ; i++ )
		swap(ar[l+i],ar[r-i]);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		ans = 0;
		for( int i = 1 ; i < n ; i++ ) {
			int idx = -1;
			for( int j = i ; j <= n ; j++ )
				if(ar[j] == i) {
					idx = j;
					break;
				}
			ans += idx-i+1;
			rev(i,idx);
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
