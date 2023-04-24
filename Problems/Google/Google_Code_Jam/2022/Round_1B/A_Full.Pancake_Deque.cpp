#include <bits/stdc++.h>
#define maxn 100003
using namespace std;

int T,n;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		int l=1 , r=n , ans=0 , mx=-1;
		while(l <= r) {
			if(ar[l] <= ar[r]) {
				ans += (ar[l] >= mx);
				mx = max(mx,ar[l++]);
			}
			else {
				ans += (ar[r] >= mx);
				mx = max(mx,ar[r--]);
			}
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
