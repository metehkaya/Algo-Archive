#include <bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long LL;

LL k;
int T,n;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%lld",&n,&k);
		int mn = INT_MAX , mx = INT_MIN;
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&ar[i]);
			mn = min(mn,ar[i]);
			mx = max(mx,ar[i]);
		}
		if(k % 2 == 1) {
			for( int i = 0 ; i < n ; i++ )
				printf("%d ",mx-ar[i]);
			puts("");
		}
		else {
			for( int i = 0 ; i < n ; i++ )
				printf("%d ",ar[i]-mn);
			puts("");
		}
	}
	return 0;
}
