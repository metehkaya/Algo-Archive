#include <bits/stdc++.h>
#define maxn 200003
#define pb push_back
using namespace std;
typedef long long LL;

int T,n,m;
int a[maxn];
int b[maxn];
LL add[maxn];
LL ans[maxn];
int lvl[maxn];
vector<int> adj[maxn];

void solve(int u , int dad) {
	ans[u] = ans[dad] + add[u];
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v != dad)
			solve(v,u);
	}
}

void dfs(int u , int dad) {
	lvl[u] = lvl[dad]+1;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v != dad)
			dfs(v,u);
	}
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i < n ; i++ ) {
		scanf("%d%d",&a[i],&b[i]);
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	dfs(1,0);
	scanf("%d",&m);
	for( int q = 0 ; q < m ; q++ ) {
		int t,e,x;
		scanf("%d%d%d",&t,&e,&x);
		int u = a[e] , v = b[e];
		if(t == 2)
			swap(u,v);
		if(lvl[u] > lvl[v])
			add[u] += x;
		else {
			add[1] += x;
			add[v] -= x;
		}
	}
	solve(1,0);
	for( int i = 1 ; i <= n ; i++ )
		printf("%lld\n",ans[i]);
	return 0;
}
