#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int n,k=2;
int ar[maxn];
int dp[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 1 ; i < n ; i++ ) {
		dp[i] = INT_MAX;
		for( int j = 1 ; j <= min(i,k) ; j++ )
			dp[i] = min( dp[i] , dp[i-j] + abs( ar[i] - ar[i-j] ) );
	}
	printf("%d\n",dp[n-1]);
	return 0;
}
