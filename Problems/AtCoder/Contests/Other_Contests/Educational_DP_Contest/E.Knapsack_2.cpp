#include <bits/stdc++.h>
#define maxn 100
#define maxv 1000
using namespace std;

int n,m;
int w[maxn];
int v[maxn];
int ar[maxn];
int dp[maxn*maxv+1];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d%d",&w[i],&v[i]);
	for( int i = 1 ; i <= n*maxv ; i++ )
		dp[i] = INT_MAX;
	for( int i = 0 ; i < n ; i++ )
		for( int j = n*maxv - v[i] ; j >= 0 ; j-- )
			if( dp[j] <= m )
				dp[j+v[i]] = min( dp[j+v[i]] , dp[j] + w[i] );
	for( int i = n*maxv ; i >= 0 ; i-- )
		if( dp[i] <= m ) {
			printf("%d\n",i);
			break;
		}
	return 0;
}
