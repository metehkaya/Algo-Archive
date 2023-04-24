#include <bits/stdc++.h>
using namespace std;

int T,n,m;
string s,t;
int dp[61][61];
int best[61][61];

int f(int i , int j) {
	if(i == n && j == m)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = INT_MAX;
	if(i < n && j < m && s[i] == t[j]) {
		int val = f(i+1,j+1);
		if(val < dp[i][j])
			dp[i][j] = val , best[i][j] = 0;
	}
	if(i < n && j < m && s[i] != t[j]) {
		int val = f(i+1,j+1) + 1;
		if(val < dp[i][j])
			dp[i][j] = val , best[i][j] = 1;
	}
	if(i < n) {
		int val = f(i+1,j) + 1;
		if(val < dp[i][j])
			dp[i][j] = val , best[i][j] = 2;
	}
	if(j < m) {
		int val = f(i,j+1) + 1;
		if(val < dp[i][j])
			dp[i][j] = val , best[i][j] = 3;
	}
	return dp[i][j];
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> s >> t;
		n = s.length();
		m = t.length();
		memset(dp,-1,sizeof(dp));
		int cost = f(0,0);
		string ans = "";
		int i = 0 , j = 0 , curr = 0;
		while(curr < cost/2) {
			if(best[i][j] == 0) {
				ans.push_back(s[i]);
				i++,j++;
			}
			else if(best[i][j] == 1) {
				curr++;
				ans.push_back(t[j]);
				i++,j++;
			}
			else if(best[i][j] == 2) {
				curr++;
				i++;
			}
			else if(best[i][j] == 3) {
				curr++;
				ans.push_back(t[j]);
				j++;
			}
		}
		while(i < n)
			ans.push_back(s[i++]);
		printf("Case #%d: %s\n",tc,ans.c_str());
	}
	return 0;
}
