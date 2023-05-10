#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;

class MapleTreeEasy {
	public:
	int n;
	LL dp[50][2];
	vector<int> adj[50];
	LL f(int u , int st) {
		if(dp[u][st] != -1)
			return dp[u][st];
		dp[u][st] = 0;
		int deg = adj[u].size();
		int sum1 = 0;
		for( int i = 0 ; i < deg ; i++ )
			sum1 += f(adj[u][i],1);
		if(!st) {
			for( int i = 0 ; i < deg ; i++ )
				for( int j = i+1 ; j < deg ; j++ )
					dp[u][st] += f(adj[u][i],1)*f(adj[u][j],1);
			dp[u][st] = 2*dp[u][st] + sum1;
		}
		else
			dp[u][st] = 2*sum1;
		dp[u][st]++;
		if(!st)
			for( int i = 0 ; i < deg ; i++ )
				dp[u][st] += f(adj[u][i],0);
		return dp[u][st];
	}
    LL count(vector <int> p) {
		n = p.size();
		for( int i = 0 ; i < n ; i++ )
			adj[p[i]].pb(i+1);
		n++;
		memset(dp,-1,sizeof(dp));
		LL ans = 0;
		ans = f(0,0);
		return ans;
	}
};
