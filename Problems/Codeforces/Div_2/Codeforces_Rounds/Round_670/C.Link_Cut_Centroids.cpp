#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100003
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int T,n;
int best;
int cnt[maxn];
pi edge[maxn];
vector<int> centers;
vector<int> adj[maxn];

void reset() {
	best = INT_MAX;
	centers.clear();
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
}

int dfs(int u , int dad) {
	cnt[u] = 0;
	int mx = INT_MIN;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v != dad) {
			int sz = dfs(v,u);
			mx = max(mx,sz);
			cnt[u] += sz;
		}
	}
	cnt[u]++;
	mx = max(mx,n-cnt[u]);
	if(mx < best) {
		best = mx;
		centers.clear();
		centers.pb(u);
	}
	else if(mx == best)
		centers.pb(u);
	return cnt[u];
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		for( int i = 1 , u,v ; i < n ; i++ ) {
			scanf("%d%d",&u,&v);
			adj[u].pb(v);
			adj[v].pb(u);
			edge[i] = pi(u,v);
		}
		dfs(1,0);
		if(centers.size() == 1) {
			int u = edge[1].fi;
			int v = edge[1].se;
			printf("%d %d\n",u,v);
			printf("%d %d\n",u,v);
		}
		else {
			int u = centers[0];
			int v = centers[1];
			int degu = adj[u].size();
			int degv = adj[v].size();
			bool found = false;
			for( int i = 0 ; !found && i < degu ; i++ )
				if(adj[u][i] != v) {
					printf("%d %d\n",u,adj[u][i]);
					printf("%d %d\n",v,adj[u][i]);
					found = true;
				}
			for( int i = 0 ; !found && i < degv ; i++ )
				if(adj[v][i] != u) {
					printf("%d %d\n",v,adj[v][i]);
					printf("%d %d\n",u,adj[v][i]);
					found = true;
				}
		}
	}
	return 0;
}
