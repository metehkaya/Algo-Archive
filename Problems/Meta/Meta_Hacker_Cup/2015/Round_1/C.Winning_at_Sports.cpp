#include <bits/stdc++.h>
#define maxn 2001
#define mod 1000000007
using namespace std;

int T,n,m;
int dp1[maxn][maxn];
int dp2[maxn][maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		string s;
		cin >> s;
		int len = s.length() , idx = -1;
		for( int i = 0 ; i < len ; i++ )
			if(s[i] == '-')
				idx = i;
		n = m = 0;
		for( int i = 0 ; i < idx ; i++ )
			n = 10*n + s[i]-'0';
		for( int i = idx+1 ; i < len ; i++ )
			m = 10*m + s[i]-'0';
		dp1[1][0] = 1;
		for( int i = 2 ; i <= n ; i++ )
			for( int j = 0 ; j < i ; j++ ) {
				if(i-1 > j)
					dp1[i][j] += dp1[i-1][j];
				if(j)
					dp1[i][j] += dp1[i][j-1];
				dp1[i][j] %= mod;
			}
		dp2[0][0] = 1;
		for( int i = 0 ; i <= m ; i++ )
			for( int j = i ; j <= m ; j++ ) {
				if(i)
					dp2[i][j] += dp2[i-1][j];
				if(j && i <= j-1)
					dp2[i][j] += dp2[i][j-1];
				dp2[i][j] %= mod;
			}
		printf("Case #%d: %d %d\n",tc,dp1[n][m],dp2[m][m]);
	}
	return 0;
}
