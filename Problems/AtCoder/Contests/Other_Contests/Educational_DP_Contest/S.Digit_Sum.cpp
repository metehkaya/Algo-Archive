#include <bits/stdc++.h>
#define maxn 100003
#define maxk 100
#define mod 1000000007
using namespace std;

int n,k;
char s[maxn];
int dp[maxn][maxk][2];

int f(int curr, int sum, bool isSmaller) {
	if(curr == n)
		return (sum == 0);
	if(dp[curr][sum][isSmaller] != -1)
		return dp[curr][sum][isSmaller];
	dp[curr][sum][isSmaller] = 0;
	int val = s[curr] - '0';
	for( int i = 0 ; i <= val ; i++ )
		dp[curr][sum][isSmaller] = ( dp[curr][sum][isSmaller] + f(curr+1, (sum+i)%k, isSmaller || (i<val)) ) % mod;
	if(isSmaller)
		for( int i = val+1 ; i <= 9 ; i++ )
			dp[curr][sum][isSmaller] = ( dp[curr][sum][isSmaller] + f(curr+1, (sum+i)%k, true) ) % mod;
	return dp[curr][sum][isSmaller];
}

int main() {
	scanf("%s%d",s,&k);
	n = strlen(s);
	memset(dp, -1, sizeof(dp));
	printf("%d\n",(f(0,0,0)-1+mod)%mod);
	return 0;
}
