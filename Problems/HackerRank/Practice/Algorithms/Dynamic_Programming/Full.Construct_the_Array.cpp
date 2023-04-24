#include <bits/stdc++.h>
#define maxn 100003
#define mod 1000000007LL
using namespace std;
typedef long long LL;

int n,k,x;
LL dp[maxn][2];

LL f(int curr , int st) {
	if(curr == n)
		return st;
	if(dp[curr][st] != -1)
		return dp[curr][st];
	dp[curr][st] = 0;
	if(st == 1)
		dp[curr][st] = ( (k-1) * f(curr+1,0) ) % mod;
	else {
		dp[curr][st] = f(curr+1,1);
		dp[curr][st] = ( dp[curr][st] + ( (k-2) * f(curr+1,0) ) % mod ) % mod;
	}
	return dp[curr][st];
}

int main() {
	scanf("%d%d%d",&n,&k,&x);
	memset(dp,-1,sizeof(dp));
	printf("%lld\n",f(1,(x==1)));
	return 0;
}
