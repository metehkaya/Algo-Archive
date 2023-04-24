#include <bits/stdc++.h>
#define maxn 100
#define maxm 5001
using namespace std;
typedef long long LL;

int T,n,m,g;
int ar[maxn];
int dp[maxm];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&g);
		int sum = 0;
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&ar[i]);
			sum += ar[i];
		}
		m = sum/2;
		dp[0] = tc;
		for( int i = 0 ; i < n ; i++ )
			for( int j = m ; j >= ar[i] ; j-- )
				if( dp[j-ar[i]] == tc )
					dp[j] = tc;
		int t = m;
		while( dp[t] != tc )
			t--;
		t = sum-t;
		if(t <= g)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
