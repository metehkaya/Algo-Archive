#include <bits/stdc++.h>
#define maxn 1003
using namespace std;
typedef long long LL;
typedef pair<LL,int> pi;

int n,k;
LL sum;
LL ar[maxn];
LL dp[maxn];
set<pi> myset;

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i < n ; i++ ) {
		scanf("%lld",&ar[i]);
		sum += ar[i];
	}
	myset.insert(pi(0,0));
	for( int i = 1 ; i <= n ; i++ ) {
		pi temp = *(myset.begin());
		dp[i] = ar[i] + temp.first;
		if(i >= k)
			myset.erase(pi(dp[i-k],i-k));
		myset.insert(pi(dp[i],i));
	}
	printf("%lld\n",sum-dp[n]);
	return 0;
}
