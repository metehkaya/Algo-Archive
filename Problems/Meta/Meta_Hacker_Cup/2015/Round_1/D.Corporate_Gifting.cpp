#include <bits/stdc++.h>
#define maxk 20
#define maxn 200001
using namespace std;

int T,n;
vector<int> nodes;
int dp[maxn][maxk];
vector<int> adj[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	nodes.clear();
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
}

void bfs() {
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		nodes.push_back(u);
		for( int i = 0 ; i < adj[u].size() ; i++ )
			Q.push(adj[u][i]);
	}
}

int solve() {
	for( int k = n-1 ; k >= 0 ; k-- ) {
		int u = nodes[k];
		int sz = adj[u].size();
		vector<int> best1(sz,-1);
		vector<int> best2(sz,-1);
		for( int i = 0 ; i < sz ; i++ ) {
			int v = adj[u][i];
			for( int j = 0 ; j < maxk ; j++ )
				if(best1[i] == -1 || dp[v][j] < dp[v][best1[i]]) {
					best2[i] = best1[i];
					best1[i] = j;
				}
				else if(best2[i] == -1 || dp[v][j] < dp[v][best2[i]])
					best2[i] = j;
		}
		for( int j = 0 ; j < maxk ; j++ ) {
			dp[u][j] = j+1;
			for( int i = 0 ; i < sz ; i++ ) {
				int v = adj[u][i];
				if(best1[i] != j)
					dp[u][j] += dp[v][best1[i]];
				else
					dp[u][j] += dp[v][best2[i]];
			}
		}
	}
	int ans = INT_MAX;
	for( int i = 0 ; i < maxk ; i++ )
		ans = min(ans,dp[1][i]);
	return ans;
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		for( int i = 1 , p ; i <= n ; i++ ) {
			scanf("%d",&p);
			adj[p].push_back(i);
		}
		bfs();
		printf("Case #%d: %d\n",tc,solve());
	}
	return 0;
}
