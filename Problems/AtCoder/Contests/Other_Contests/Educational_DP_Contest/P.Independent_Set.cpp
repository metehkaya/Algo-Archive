#include <bits/stdc++.h>
#define maxn 100001
#define mod 1000000007
#define pb push_back
using namespace std;
typedef long long LL;

int n;
int dp[maxn][2];
vector<int> adj[maxn];

int f( int node , int dad , bool k ) {
	if(dp[node][k] != -1)
		return dp[node][k];
	int add = 1;
	dp[node][k] = 1;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i];
		if( to != dad ) {
			dp[node][k] = ( dp[node][k] * (LL) f(to,node,1) ) % mod;
			add = ( add * (LL) f(to,node,0) ) % mod;
		}
	}
	if(k)
		dp[node][k] = ( dp[node][k] + add ) % mod;
	return dp[node][k];
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i < n ; i++ ) {
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n",f(1,0,1));
	return 0;
}
