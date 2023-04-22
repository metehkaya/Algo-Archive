#include <bits/stdc++.h>
#define fi first
#define se second
#define lim 1000
#define maxn 200003
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int T,n,m,q,sumq;
pi edgew[maxn];
int cntq[maxn];
int checkheavy[maxn];
int checklight[maxn];
vector<pi> queries;
vector<pi> adj[maxn];
vector<pi> adjl[maxn];
vector<pi> adjh[maxn];
set<int> nodeqs[maxn];
map<int,LL> score[maxn];
vector<int> nodeqv[maxn];
map<int,int> gscore[maxn];
vector<int> nodeqvl[maxn];
vector<int> nodeqvh[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	queries.clear();
	for( int i = 1 ; i <= n ; i++ ) {
		edgew[i] = pi(0,0);
		cntq[i] = 0;
		checkheavy[i] = 0;
		checklight[i] = 0;
		adj[i].clear();
		adjl[i].clear();
		adjh[i].clear();
		score[i].clear();
		gscore[i].clear();
		nodeqs[i].clear();
		nodeqv[i].clear();
		nodeqvl[i].clear();
		nodeqvh[i].clear();
	}
}

void addScore(int u , int v , int w) {
	if(u > v)
		swap(u,v);
	score[u][v] += w;
}

void input() {
	scanf("%d%d%d",&n,&m,&q);
	sumq += q;
	for( int i = 0 , u,v,w ; i < m ; i++ ) {
		scanf("%d%d%d",&u,&v,&w);
		if(u > v)
			swap(u,v);
		adj[u].pb(pi(w,v));
		adj[v].pb(pi(w,u));
		gscore[u][v] = w;
	}
	for( int i = 0 , u,v ; i < q ; i++ ) {
		scanf("%d%d",&u,&v);
		if(u > v)
			swap(u,v);
		queries.pb(pi(u,v));
		nodeqs[u].insert(v);
		nodeqs[v].insert(u);
	}
}

void heavylight() {
	for( int u = 1 ; u <= n ; u++ )
		cntq[u] = nodeqs[u].size();
	for( int u = 1 ; u <= n ; u++ ) {
		vector<int> temp(nodeqs[u].begin(),nodeqs[u].end());
		nodeqv[u] = temp;
		int sz = (int) nodeqv[u].size();
		for( int i = 0 ; i < sz ; i++ ) {
			int v = nodeqv[u][i];
			if(cntq[v] <= lim)
				nodeqvl[u].pb(v);
			else
				nodeqvh[u].pb(v);
		}
	}
	for( int u = 1 ; u <= n ; u++ ) {
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int w = adj[u][i].fi;
			int v = adj[u][i].se;
			if(cntq[v] <= lim)
				adjl[u].pb(pi(w,v));
			else
				adjh[u].pb(pi(w,v));
		}
		sort(adjl[u].begin(),adjl[u].end());
		sort(adjh[u].begin(),adjh[u].end());
	}
}

void solveh(int u) {
	int degh = adjh[u].size();
	for( int i = degh-1 ; i >= 0 ; i-- ) {
		int w = adjh[u][i].fi;
		int v = adjh[u][i].se;
		int szv = nodeqvh[v].size();
		for( int j = 0 ; j < szv ; j++ ) {
			int v2 = nodeqvh[v][j];
			if(checkheavy[v2] == u)
				addScore(v,v2,w);
		}
		checkheavy[v] = u;
		edgew[v] = pi(w,u);
	}
}

void solvel(int u) {
	int degl = adjl[u].size();
	for( int i = degl-1 ; i >= 0 ; i-- ) {
		int w = adjl[u][i].fi;
		int v = adjl[u][i].se;
		int szv = nodeqvl[v].size();
		for( int j = 0 ; j < szv ; j++ ) {
			int v2 = nodeqvl[v][j];
			if(checklight[v2] == u)
				addScore(v,v2,w);
		}
		checklight[v] = u;
		szv = nodeqvh[v].size();
		for( int j = 0 ; j < szv ; j++ ) {
			int v2 = nodeqvh[v][j];
			if(edgew[v2].se == u) {
				int w2 = edgew[v2].fi;
				addScore(v,v2,min(w,w2));
			}
		}
	}
}

void solve() {
	for( int u = 1 ; u <= n ; u++ ) {
		solveh(u);
		solvel(u);
	}
}

void output(int tc) {
	printf("Case #%d:",tc);
	for( int i = 0 ; i < q ; i++ ) {
		int u = queries[i].fi;
		int v = queries[i].se;
		printf(" %lld",score[u][v]+2*gscore[u][v]);
	}
	puts("");
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		heavylight();
		solve();
		output(tc);
	}
	return 0;
}
