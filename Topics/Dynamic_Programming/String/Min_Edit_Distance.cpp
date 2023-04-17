#include <bits/stdc++.h>
#define maxn 5003
using namespace std;

int n,m;
string s,t;
int dp[maxn][maxn];

int f(int i , int j) {
	if(i == n)
		return m-j;
	if(j == m)
		return n-i;
	if(dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = min(f(i,j+1),f(i+1,j))+1;
	int add = (s[i] != t[j]);
	dp[i][j] = min(dp[i][j],f(i+1,j+1)+add);
	return dp[i][j];
}

int main() {
	cin >> s >> t;
	n = s.length();
	m = t.length();
	memset(dp,-1,sizeof(dp));
	printf("%d\n",f(0,0));
	return 0;
}
