#include <bits/stdc++.h>
#define maxn 200001
#define pb push_back
using namespace std;
typedef long long LL;

int n,m,t;
int ar[maxn];
int dt[maxn];
int ft[maxn];
LL tree[4*maxn];
vector<int> adj[maxn];

void dfs(int u , int dad) {
	dt[u] = ++t;
	for( int i = 0 ; i < (int) adj[u].size() ; i++ )
		if(adj[u][i] != dad)
			dfs(adj[u][i],u);
	ft[u] = t;
}

void update(int x , int val) {
	while(x <= n) {
		tree[x] += val;
		x += (x & (-x));
	}
}

LL query(int x) {
	LL res = 0;
	while(x) {
		res += tree[x];
		x -= (x & (-x));
	}
	return res;
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 1 , u , v ; i < n ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0);
	for( int i = 1 ; i <= n ; i++ )
		update(dt[i],ar[i]);
	for( int i = 0 , t , u , val ; i < m ; i++ ) {
		scanf("%d%d",&t,&u);
		if(t == 1) {
			scanf("%d",&val);
			int diff = val - ar[u];
			update(dt[u],diff);
			ar[u] = val;
		}
		else
			printf("%lld\n",query(ft[u])-query(dt[u]-1));
	}
	return 0;
}