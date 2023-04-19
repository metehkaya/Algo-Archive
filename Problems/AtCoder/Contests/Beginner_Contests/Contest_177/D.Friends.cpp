#include <bits/stdc++.h>
#define maxn 200003
#define pb push_back
using namespace std;

int n,m,ans,cnt;
bool mark[maxn];
vector<int> adj[maxn];

void dfs(int u) {
	cnt++;
	mark[u] = true;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(mark[v])
			continue;
		dfs(v);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x,y ; i < m ; i++ ) {
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for( int i = 1 ; i <= n ; i++ )
		if(!mark[i]) {
			cnt = 0;
			dfs(i);
			ans = max(ans,cnt);
		}
	printf("%d\n",ans);
	return 0;
}
