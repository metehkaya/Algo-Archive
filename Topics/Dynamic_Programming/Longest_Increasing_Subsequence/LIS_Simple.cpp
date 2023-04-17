#include <bits/stdc++.h>
#define maxn 5003
using namespace std;

int n,best;
int ar[maxn];
int dp[maxn];
int prev[maxn];

void goPrev(int id) {
	if(id == 0)
		return;
	goPrev(prev[id]);
	printf(" %d",ar[id]);
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 1 ; i <= n ; i++ ) {
		int mx = 0;
		for( int j = 1 ; j < i ; j++ )
			if(ar[j] < ar[i] && dp[j] > mx)
				mx = dp[j] , prev[i] = j;
		dp[i] = mx+1;
		if(dp[i] > dp[best])
			best = i;
	}
	printf("LIS Length: %d\n",dp[best]);
	printf("LIS:");
	goPrev(best);
	puts("");
	return 0;
}
