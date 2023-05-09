#include <bits/stdc++.h>
#define maxn 200001
using namespace std;

int n,k;
int ar[maxn];
int mn[maxn];
int sum[maxn];

bool check(int num) {
	for( int i = 1 ; i <= n ; i++ ) {
		if(ar[i] >= num)
			sum[i] = sum[i-1]+1;
		else
			sum[i] = sum[i-1]-1;
		mn[i] = min(mn[i-1],sum[i]);
	}
	for( int i = k ; i <= n ; i++ )
		if(sum[i] > mn[i-k])
			return true;
	return false;
}

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	int l = 1 , r = n , ans = -1;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(check(mid))
			ans = mid , l = mid+1;
		else
			r = mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
