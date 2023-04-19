#include <bits/stdc++.h>
#define maxn 3001
using namespace std;

int n,m;
string s,t;
int dp[maxn][maxn];

int main() {
	cin >> s >> t;
	n = s.length();
	m = t.length();
	for( int i = n-1 ; i >= 0 ; i-- )
		for( int j = m-1 ; j >= 0 ; j-- ) {
			if(s[i] == t[j])
				dp[i][j] = dp[i+1][j+1] + 1;
			dp[i][j] = max( dp[i][j] , dp[i][j+1] );
			dp[i][j] = max( dp[i][j] , dp[i+1][j] );
		}
	int i=0,j=0;
	while(i < n && j < m) {
		if(s[i] == t[j] && dp[i][j] == dp[i+1][j+1] + 1)
			j++, printf("%c",s[i++]);
		else if(dp[i][j] == dp[i][j+1])
			j++;
		else
			i++;
	}
	puts("");
	return 0;
}
