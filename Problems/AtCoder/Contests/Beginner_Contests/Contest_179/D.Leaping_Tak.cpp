#include <bits/stdc++.h>
#define maxn 200003
#define mod 998244353
using namespace std;

int n,k;
int dp[maxn];
int sum[maxn];
int l[10],r[10];

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < k ; i++ )
		scanf("%d%d",&l[i],&r[i]);
	dp[n] = 1;
	sum[n] = 1;
	for( int i = n-1 ; i >= 1 ; i-- ) {
		for( int j = 0 ; j < k ; j++ ) {
			int ll = min(i+l[j],n+1);
			int rr = min(i+r[j],n+1);
			int add = (sum[ll] - sum[rr+1] + mod) % mod;
			dp[i] = (dp[i] + add) % mod;
		}
		sum[i] = (sum[i+1] + dp[i]) % mod;
	}
	printf("%d\n",dp[1]);
	return 0;
}
