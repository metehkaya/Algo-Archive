#include <bits/stdc++.h>
#define maxn 100003
#define mod 1000000007
using namespace std;

int n,m;
int dp[maxn];

int f(int n) {
	if(n <= 1)
		return n;
	if(dp[n] != -1)
		return dp[n];
	return dp[n] = (f(n-1) + f(n-2)) % mod;
}

int main() {
	scanf("%d",&m);
	memset(dp,-1,sizeof(dp));
	while(m--) {
		scanf("%d",&n);
		printf("%d\n",f(n));
	}
	return 0;
}
