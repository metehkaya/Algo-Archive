#include <bits/stdc++.h>
#define maxn 2003
#define pb push_back
using namespace std;

int T,n,k,m;
int a[maxn];
int b[maxn];
int mark[maxn];
vector<int> v1,v2;
vector<int> adj[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	m = 0;
	v1.clear();
	v2.clear();
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
	memset(mark,0,sizeof(mark));
}

void read() {
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d%d",&a[i],&b[i]);
}

void dfs2(int node) {
	mark[node] = m;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i];
		if(!mark[to])
			dfs2(to);
	}
}

void dfs1(int node) {
	v1.pb(node);
	if(a[node])
		dfs1(a[node]);
	if(b[node])
		dfs1(b[node]);
	v2.pb(node);
}

void solve() {
	dfs1(1);
	for( int i = 0 ; i < n ; i++ ) {
		adj[v1[i]].pb(v2[i]);
		adj[v2[i]].pb(v1[i]);
	}
	for( int i = 1 ; i <= n ; i++ )
		if(!mark[i]) {
			m++;
			dfs2(i);
		}
}

void print(int tc) {
	if(m < k)
		printf("Case #%d: Impossible\n",tc);
	else {
		printf("Case #%d:",tc);
		for( int i = 1 ; i <= n ; i++ )
			printf(" %d",min(mark[i],k));
		puts("");
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		read();
		solve();
		print(tc);
	}
	return 0;
}

