#include <bits/stdc++.h>
#define fi first
#define se second
#define maxk 17
#define maxn 100001
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

struct edge {
	int x,y,len;
	bool flag;
	edge(int _x,int _y,int _len,bool _flag) {
		x = _x;
		y = _y;
		len = _len;
		flag = _flag;
	}
};

bool comp(edge a, edge b) {
	return a.len < b.len;
}

int n,m,t,ans;
int dt[maxn];
int ft[maxn];
int dad[maxn];
int lvl[maxn];
int depth[maxn];
int mxw[maxn][maxk];
int par[maxn][maxk];

vector<edge> edges;
vector<pi> adj[maxn];
map<int,int> hashh[maxn];

int find(int u) {
	if(!dad[u])
		return u;
	return u = find(dad[u]);
}

void merge(int u, int v) {
	if( lvl[v] < lvl[u] )
		dad[v] = u;
	else {
		dad[u] = v;
		if( lvl[u] == lvl[v] )
			lvl[v]++;
	}
}

void readGraph() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x,y,len ; i < m ; i++ ) {
		scanf("%d%d%d",&x,&y,&len);
		edges.pb(edge(x,y,len,false));
	}
}

void findMST() {
	sort(edges.begin(), edges.end(), comp);
	for( int i = 0 ; i < m ; i++ ) {
		int u = edges[i].x;
		int v = edges[i].y;
		u = find(u);
		v = find(v);
		if( u != v ) {
			merge(u, v);
			edges[i].flag = true;
			adj[edges[i].x].pb( pi( edges[i].y , edges[i].len ) );
			adj[edges[i].y].pb( pi( edges[i].x , edges[i].len ) );
		}
	}
}

void dfs1(int node, int daddy, int w) {
	depth[node] = depth[daddy] + 1;
	par[node][0] = daddy;
	for( int i = 1 ; i < maxk ; i++ )
		par[node][i] = par[par[node][i-1]][i-1];
	mxw[node][0] = w;
	for( int i = 1 ; i < maxk ; i++ )
		mxw[node][i] = max( mxw[node][i-1] , mxw[par[node][i-1]][i-1] );
	dt[node] = ++t;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i].fi;
		if(daddy != to)
			dfs1(to, node, adj[node][i].se);
	}
	ft[node] = t;
}

int findLCA(int u, int v) {
	if( dt[u] <= dt[v] && ft[v] <= ft[u] )
		return u;
	if( dt[v] <= dt[u] && ft[u] <= ft[v] )
		return v;
	int lca = 1;
	for( int i = maxk-1 ; i >= 0 ; i-- ) {
		int x = par[u][i];
		if(!x)
			continue;
		if( dt[x] <= dt[v] && ft[v] <= ft[x] )
			lca = x;
		else
			u = x;
	}
	return lca;
}

int findMax(int u, int d) {
	int mx = 0;
	for( int i = maxk-1 ; i >= 0 ; i-- )
		if( d & (1<<i) ) {
			mx = max( mx , mxw[u][i] );
			u = par[u][i];
		}
	return mx;
}

void hashTasks(int node, int to) {
	if(hashh[node].size() < hashh[to].size())
		hashh[node].swap(hashh[to]);
	map<int,int>::iterator it = hashh[to].begin();
	while(it != hashh[to].end()) {
		int x = (*it).fi;
		int add = (*it).se;
		if( ( hashh[node][x] += add ) == 0 )
			hashh[node].erase(x);
		it++;
	}
}

void dfs2(int node, int daddy, int w) {
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i].fi;
		if(daddy != to) {
			dfs2(to, node, adj[node][i].se);
			hashTasks(node, to);
		}
	}
	if(hashh[node].find(w) != hashh[node].end())
		ans--;
}

void solve() {
	for( int i = 0 ; i < m ; i++ )
		if( !edges[i].flag ) {
			int u = edges[i].x;
			int v = edges[i].y;
			int len = edges[i].len;
			int lca = findLCA(u,v);
			int ud = findMax(u, depth[u]-depth[lca]);
			int vd = findMax(v, depth[v]-depth[lca]);
			int d = max(ud,vd);
			if( len == d ) {
				if( ++hashh[u][d] == 0 )
					hashh[u].erase(d);
				if( ++hashh[v][d] == 0 )
					hashh[v].erase(d);
				if( --hashh[lca][d] == 0 )
					hashh[lca].erase(d);
				if( --hashh[lca][d] == 0 )
					hashh[lca].erase(d);
			}
		}
	ans = n-1;
	dfs2(1,0,0);
	printf("%d\n",ans);
}

int main() {
	readGraph();
	findMST();
	dfs1(1,0,0);
	solve();
	return 0;
}
