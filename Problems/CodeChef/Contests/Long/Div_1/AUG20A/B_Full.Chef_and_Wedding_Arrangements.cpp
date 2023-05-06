#include <bits/stdc++.h>
#define maxf 103
#define maxn 1003
using namespace std;

int T,n,k;
int ar[maxn];
int dp[maxn];
int cnt[maxf];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		dp[n+1] = 0;
		for( int i = n ; i >= 1 ; i-- ) {
			int cost = 0;
			dp[i] = INT_MAX;
			memset(cnt,0,sizeof(cnt));
			for( int j = i ; j <= n ; j++ ) {
				int v = ar[j];
				if(cnt[v] == 1)
					cost += 2;
				else if(cnt[v] > 1)
					cost++;
				cnt[v]++;
				dp[i] = min(dp[i],dp[j+1]+cost+k);
			}
		}
		printf("%d\n",dp[1]);
	}
	return 0;
}
