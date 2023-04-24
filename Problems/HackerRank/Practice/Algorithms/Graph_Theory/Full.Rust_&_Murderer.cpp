#include <bits/stdc++.h>
#define maxn 200003
#define pb push_back
using namespace std;

int T,n,m,r;
int d[maxn];
int prv[maxn];
int nxt[maxn];
int last[maxn];
bool mark[maxn];
vector<int> adj[maxn];

void bfs() {
	queue<int> Q;
	int h = (r != 1) ? 1 : 2;
	d[r] = 0;
	mark[r] = true;
	nxt[prv[r]] = nxt[r];
	prv[nxt[r]] = prv[r];
	Q.push(r);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for( int i = 0 ; i < (int) adj[u].size() ; i++ ) {
			int v = adj[u][i];
			last[v] = u;
		}
		vector<int> rem;
		for( int i = h ; i != n+1 ; i = nxt[i] )
			if( last[i] != u )
				rem.pb(i);
		for( int i = 0 ; i < (int) rem.size() ; i++ ) {
			int v = rem[i];
			d[v] = d[u] + 1;
			mark[v] = true;
			if( h == v )
				h = nxt[v];
			nxt[prv[v]] = nxt[v];
			prv[nxt[v]] = prv[v];
			Q.push(v);
		}
	}
}

void init() {
	for( int i = 1 ; i <= n ; i++ ) {
		last[i] = 0;
		prv[i] = i-1;
		nxt[i] = i+1;
		adj[i].clear();
		mark[i] = false;
	}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&m);
		init();
		for( int i = 0 , x , y ; i < m ; i++ ) {
			scanf("%d%d",&x,&y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		scanf("%d",&r);
		bfs();
		for( int i = 1 ; i <= n ; i++ )
			if( r != i )
				printf("%d ", d[i]);
		puts("");
	}
	return 0;
}
