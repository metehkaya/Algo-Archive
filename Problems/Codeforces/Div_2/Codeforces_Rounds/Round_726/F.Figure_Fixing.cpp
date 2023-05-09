#include <bits/stdc++.h>
#define maxn 200003
#define pb push_back
using namespace std;
typedef long long LL;

int T,n,m;
int s[maxn];
int t[maxn];
int mark[maxn];
vector<int> adj[maxn];

void dfs(int u , int c) {
	mark[u] = c;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(!mark[v])
			dfs(v,3-c);
	}
}

void reset() {
	for( int i = 1 ; i <= n ; i++ ) {
		mark[i] = 0;
		adj[i].clear();
	}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&m);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&s[i]);
		LL diffsum = 0;
		for( int i = 1 ; i <= n ; i++ ) {
			scanf("%d",&t[i]);
			diffsum += t[i]-s[i];
		}
		for( int i = 0 , u,v ; i < m ; i++ ) {
			scanf("%d%d",&u,&v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		diffsum = llabs(diffsum);
		if(diffsum % 2)
			puts("NO");
		else {
			dfs(1,1);
			diffsum = 0;
			bool same = false;
			for( int u = 1 ; u <= n ; u++ ) {
				if(mark[u] == 1)
					diffsum += t[u]-s[u];
				else
					diffsum += s[u]-t[u];
				int deg = adj[u].size();
				for( int j = 0 ; j < deg ; j++ )
					if(mark[u] == mark[adj[u][j]])
						same = true;
			}
			if(same || diffsum == 0)
				puts("YES");
			else
				puts("NO");
		}
		reset();
	}
	return 0;
}
