#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 1003
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

int T,n,k;
int dad[maxn];
bool mark[maxn];
int salary[maxn];
int nextSal[maxn];
int mat[maxn][maxn];
vector<pii> v;
set<int> nodes;
vector<int> G[maxn];
vector<int> adj[maxn];

void dfs(int u) {
	mark[u] = true;
	nodes.insert(u);
	int deg = G[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int w = G[u][i];
		if(!mark[w])
			dfs(w);
	}
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= n ; j++ ) {
			scanf("%d",&mat[i][j]);
			if(i < j)
				v.pb(pii(mat[i][j],pi(i,j)));
		}
	k = n;
	int m = v.size();
	sort(v.begin(),v.end());
	for( int i = 1 ; i <= n ; i++ ) {
		salary[i] = mat[i][i];
		dad[i] = i;
	}
	for( int l = 0 , r = 0 ; l < m ; l = r ) {
		memset(mark,false,sizeof(mark));
		for( int i = 1 ; i <= n ; i++ )
			G[i].clear();
		while(r < m && v[l].fi == v[r].fi)
			r++;
		for( int i = l ; i < r ; i++ ) {
			int u = v[i].se.fi;
			int w = v[i].se.se;
			nextSal[u] = nextSal[w] = v[i].fi;
			G[u].pb(w);
			G[w].pb(u);
		}
		for( int i = 1 ; i <= n ; i++ )
			if(!mark[i] && !G[i].empty()) {
				nodes.clear();
				dfs(i);
				salary[++k] = nextSal[i];
				set<int> pars;
				set<int>::iterator it;
				for( it = nodes.begin() ; it != nodes.end() ; it++ ) {
					int u = (*it);
					pars.insert(dad[u]);
				}
				for( it = pars.begin() ; it != pars.end() ; it++ ) {
					int u = (*it);
					adj[k].pb(u);
				}
				for( it = nodes.begin() ; it != nodes.end() ; it++ ) {
					int u = (*it);
					dad[u] = k;
				}
			}
	}
	printf("%d\n",k);
	for( int i = 1 ; i <= k ; i++ )
		printf("%d ",salary[i]);
	puts("");
	printf("%d\n",k);
	for( int u = n+1 ; u <= k ; u++ ) {
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			printf("%d %d\n",v,u);
		}
	}
	return 0;
}
