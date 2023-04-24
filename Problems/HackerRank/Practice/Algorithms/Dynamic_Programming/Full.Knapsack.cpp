#include <bits/stdc++.h>
#define maxn 2001
using namespace std;

int T,n,m;
int dp[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		dp[0] = tc;
		scanf("%d%d",&n,&m);
		for( int i = 0 , x ; i < n ; i++ ) {
			scanf("%d",&x);
			for( int j = x ; j <= m ; j++ )
				if( dp[j-x] == tc )
					dp[j] = tc;
		}
		for( int i = m ; i >= 0 ; i-- )
			if( dp[i] == tc ) {
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}
