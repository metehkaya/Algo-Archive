#include <bits/stdc++.h>
#define maxn 5001
#define pb push_back
using namespace std;

int n,m,n1,n2,n3,g;
int col[maxn];
int ans[maxn];
int group[maxn];
int cnt[maxn][3];
int dp[maxn][maxn];
vector<int> adj[maxn];
vector<int> nodes[maxn][3];

void noSol() {
	puts("NO");
	exit(0);
}

void dfs(int u , int c) {
	col[u] = c;
	cnt[g][c]++;
	group[u] = g;
	nodes[g][c].pb(u);
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(group[v] && c == col[v])
			noSol();
		else if(!group[v])
			dfs(v,3-c);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&n1,&n2,&n3);
	for( int i = 0 , x,y ; i < m ; i++ ) {
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dp[0][0] = 1;
	for( int i = 1 ; i <= n ; i++ )
		if(!group[i]) {
			g++;
			dfs(i,1);
			for( int j = 0 ; j <= n ; j++ )
				if(dp[g-1][j]) {
					dp[g][j+cnt[g][1]] = 1;
					dp[g][j+cnt[g][2]] = 2;
				}
		}
	if(!dp[g][n2])
		noSol();
	int x = g , y = n2;
	while(x) {
		int k = dp[x][y];
		for( int i = 0 ; i < cnt[x][k] ; i++ )
			ans[nodes[x][k][i]] = 2;
		int l = 3-k;
		for( int i = 0 ; i < cnt[x][l] ; i++ ) {
			if(n1-- > 0)
				ans[nodes[x][l][i]] = 1;
			else
				ans[nodes[x][l][i]] = 3;
		}
		y -= cnt[x--][k];
	}
	puts("YES");
	for( int i = 1 ; i <= n ; i++ )
		printf("%d",ans[i]);
	return 0;
}
