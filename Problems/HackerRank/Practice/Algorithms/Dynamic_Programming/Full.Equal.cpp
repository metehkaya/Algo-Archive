#include <bits/stdc++.h>
#define maxc 1011
#define maxn 10000
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int T,n;
int a[maxn];
int dp[maxc];
int v[2] = {2,5};

int main() {
	for( int i = 0 ; i < maxc ; i++ )
		dp[i] = i;
	for( int t = 0 ; t < 2 ; t++ )
		for( int i = v[t] ; i < maxc ; i++ )
			dp[i] = min( dp[i] , dp[i-v[t]] + 1 );
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&a[i]);
		int mn = a[0];
		for( int i = 1 ; i < n ; i++ )
			mn = min(mn,a[i]);
		int ans = (1<<30);
		for( int val = mn ; val >= mn-10 ; val-- ) {
			int sum = 0;
			for( int i = 0 ; i < n ; i++ )
				sum += dp[a[i]-val];
			ans = min(ans,sum);
		}
		printf("%d\n",ans);
	}
	return 0;
}
