#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define maxk 20
#define maxn 800003
using namespace std;

int T,n,t,ans;
int dt[maxn];
int ft[maxn];
int col[maxn];
int adjcnt[maxn];
int par[maxn][maxk];
vector<int> nodes;
vector<int> adj[maxn];
set<int> colset[maxn];
map<int,vector<int> > mp;
vector<int> delcols[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	t = 0;
	mp.clear();
	nodes.clear();
	for( int i = 1 ; i <= n ; i++ ) {
		adj[i].clear();
		colset[i].clear();
		delcols[i].clear();
		col[i] = 0;
		adjcnt[i] = 0;
		dt[i] = ft[i] = 0;
		for( int k = 0 ; k < maxk ; k++ )
			par[i][k] = 0;
	}
}

void input() {
	scanf("%d",&n);
	for( int i = 1 ,u,v ; i < n ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for( int i = 1 , f ; i <= n ; i++ ) {
		scanf("%d",&f);
		mp[f].push_back(i);
	}
}

int lca(int u , int v) {
	if(dt[u] <= dt[v] && ft[v] <= ft[u])
		return u;
	if(dt[v] <= dt[u] && ft[u] <= ft[v])
		return v;
	int res = 0 , curr = u;
	for( int k = maxk-1 ; k >= 0 ; k-- ) {
		int temp = par[curr][k];
		if(temp == 0)
			continue;
		if(dt[temp] <= dt[v] && ft[v] <= ft[temp])
			res = temp;
		else
			curr = temp;
	}
	return res;
}

void dfs() {
	stack<int> st;
	st.push(1);
	while(!st.empty()) {
		int u = st.top();
		if(adjcnt[u] == adj[u].size()) {
			st.pop();
			ft[u] = t;
			nodes.pb(u);
		}
		else {
			if(adjcnt[u] == 0) {
				dt[u] = ++t;
				for( int k = 1 ; k < maxk ; k++ )
					par[u][k] = par[par[u][k-1]][k-1];
			}
			int v = adj[u][adjcnt[u]++];
			if(dt[v] == 0) {
				par[v][0] = u;
				st.push(v);
			}
		}
	}
}

void freqs() {
	map<int,vector<int> >::iterator it;
	for( it = mp.begin() ; it != mp.end() ; it++ ) {
		int val = it->fi;
		vector<int> v = it->se;
		int sz = v.size();
		if(sz > 1) {
			int LCA = v[0];
			col[LCA] = val;
			colset[LCA].insert(val);
			for( int i = 1 ; i < sz ; i++ ) {
				col[v[i]] = val;
				colset[v[i]].insert(val);
				LCA = lca(LCA,v[i]);
			}
			delcols[LCA].pb(val);
		}
	}
}

void calc() {
	ans = n-1;
	for( int i = 0 ; i < n ; i++ ) {
		int u = nodes[i];
		int deg = adj[u].size();
		int mx = 0 , id = 0;
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			if(v == par[u][0])
				continue;
			if(colset[v].size() > mx)
				mx = colset[v].size() , id = v;
		}
		if(id)
			swap(colset[u],colset[id]);
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			if(v == par[u][0])
				continue;
			if(v == id) {
				colset[v].clear();
				continue;
			}
			set<int> s = colset[v];
			set<int>::iterator it;
			for( it = s.begin() ; it != s.end() ; it++ )
				colset[u].insert((*it));
			colset[v].clear();
		}
		if(col[u])
			colset[u].insert(col[u]);
		int delcolssz = delcols[u].size();
		for( int i = 0 ; i < delcolssz ; i++ ) {
			int val = delcols[u][i];
			colset[u].erase(val);
		}
		if(!colset[u].empty())
			ans--;
	}
}

void solve() {
	dfs();
	freqs();
	calc();
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
