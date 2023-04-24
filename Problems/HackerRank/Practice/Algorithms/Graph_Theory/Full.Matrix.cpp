#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100000
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int n,m;
bool mark[maxn];
LL dp[maxn][2];
vector<pi>adj[maxn];
vector<pi>tree[maxn];

bool dfs(int node, int dad) {
	bool res = mark[node];
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i].fi;
		if(to != dad) {
			bool tmp = dfs(to, node);
			if(tmp) {
				res = true;
				tree[node].pb(adj[node][i]);
			}
		}
	}
	return res;
}

LL solve(int node, bool k, int edge) {
	if(dp[node][k] != -1)
		return dp[node][k];
	if(k) {
		dp[node][1] = solve(node,0,edge) + edge;
		if(!mark[node]) {
			LL sum = 0;
			for( int i = 0 ; i < (int) tree[node].size() ; i++ ) {
				int to = tree[node][i].fi;
				int edge = tree[node][i].se;
				sum += solve(to, 1, edge);
			}
			dp[node][1] = min(dp[node][1], sum);
		}
	}
	else {
		if(tree[node].size()) {
			LL sum = 0, best = -(1LL << 60);
			for( int i = 0 ; i < (int) tree[node].size() ; i++ ) {
				int to = tree[node][i].fi;
				int edge = tree[node][i].se;
				LL val0 = solve(to, 0, edge);
				LL val1 = solve(to, 1, edge);
				sum += val1;
				best = max(best, val1-val0);
			}
			if(mark[node])
				dp[node][0] = sum;
			else
				dp[node][0] = sum-best;
		}
		else
			dp[node][0] = 0;
	}
	return dp[node][k];
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 , x,y,z ; i < n ; i++ ) {
		scanf("%d%d%d",&x,&y,&z);
		adj[x].pb(pi(y,z));
		adj[y].pb(pi(x,z));
	}
	for( int i = 0 , x ; i < m ; i++ ) {
		scanf("%d",&x);
		mark[x] = true;
	}
	dfs(0,0);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n",solve(0,0,0));
	return 0;
}
