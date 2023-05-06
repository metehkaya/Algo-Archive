#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 101
#define maxk (1<<12)
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

short times;
int T,n,k,K,t,tc,lastT;
int dt[maxn];
int ft[maxn];
int node[maxn];
int edge[maxn];
int ans[maxn][maxk];
short mark[maxn][maxn][maxk];
vector<pi> adj[maxn];

void reset() {
	t = 0;
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
}

void input() {
	scanf("%d%d",&n,&k);
	K = (1<<k);
	for( int i = 1 , u,v,c ; i < n ; i++ ) {
		scanf("%d%d%d",&u,&v,&c);
		adj[u].pb(pi(v,c-1));
		adj[v].pb(pi(u,c-1));
	}
}

void dfs(int u , int dad , int e) {
	dt[u] = ++t;
	node[t] = u;
	edge[u] = e;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i].fi;
		int c = adj[u][i].se;
		if(v == dad)
			continue;
		dfs(v,u,(1<<c));
	}
	ft[u] = t;
}

void f(int t , int cnt , int mask) {
	if(t == lastT) {
		ans[cnt][mask] = tc;
		return;
	}
	if(mark[t][cnt][mask] == times)
		return;
	mark[t][cnt][mask] = times;
	int u = node[t];
	f(t+1,cnt+1,mask);
	f(ft[u]+1,cnt,(mask|edge[u]));
}

void solve() {
	int root = (LL) rand()*rand()%n + 1;
	dfs(root,0,0);
	for( int i = 1 ; i <= n ; i++ ) {
		times++;
		lastT = ft[i]+1;
		f(dt[i]+1,1,edge[i]);
	}
	for( int i = 1 ; i <= n ; i++ , puts("") )
		for( int j = 0 ; j < K ; j++ )
			printf("%d",ans[i][j]==tc);
}

int main() {
	srand(time(NULL));
	scanf("%d",&T);
	for( tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
	}
	return 0;
}
