#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
typedef long long LL;

int T,n,k;
int a[maxn];

bool check(int gDiff) {
	LL cnt = 0;
	for( int i = 1 ; i < n ; i++ ) {
		int diff = a[i]-a[i-1];
		cnt += (diff+gDiff-1) / gDiff - 1;
	}
	return (cnt <= k);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		int maxDiff = 0;
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&a[i]);
			if(i > 0)
				maxDiff = max(maxDiff, a[i]-a[i-1]);
		}
		int l=1,r=maxDiff,ans=maxDiff;
		while(l <= r) {
			int mid = (l+r)>>1;
			if(check(mid))
				ans=mid, r=mid-1;
			else
				l=mid+1;
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}
