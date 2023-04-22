#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 301
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

int T,n,m;
string s[maxn];
int dp[maxn][maxn];
int pref[maxn][maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void prefs() {
	queue<pii> Q;
	Q.push(pii(pi(1,n),0));
	while(!Q.empty()) {
		pii temp = Q.front();
		Q.pop();
		int l = temp.fi.fi;
		int r = temp.fi.se;
		int k = temp.se;
		if(l == r)
			continue;
		for( int i = l ; i < r ; i++ )
			for( int j = i+1 ; j <= r ; j++ )
				pref[i][j] = k;
		if(s[l].length() == k)
			l++;
		for( int i = l ; i <= r ; l = i ) {
			while(i <= r && s[i][k] == s[l][k])
				i++;
			if(l < i-1)
				Q.push(pii(pi(l,i-1),k+1));
		}
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&m);
		for( int i = 1 ; i <= n ; i++ )
			cin >> s[i];
		sort(s+1,s+n+1);
		prefs();
		for( int i = 1 ; i <= n ; i++ ) {
			dp[i][1] = s[i].length();
			for( int k = 2 ; k <= i ; k++ ) {
				dp[i][k] = INT_MAX;
				for( int j = k-1 ; j < i ; j++ )
					dp[i][k] = min( dp[i][k] , dp[j][k-1] + (int) s[i].length() + (int) s[j].length() - 2*pref[j][i] );
			}
		}
		int ans = INT_MAX;
		for( int i = m ; i <= n ; i++ )
			ans = min( ans , dp[i][m] + (int) s[i].length() );
		printf("Case #%d: %d\n",tc,ans+m);
	}
	return 0;
}
