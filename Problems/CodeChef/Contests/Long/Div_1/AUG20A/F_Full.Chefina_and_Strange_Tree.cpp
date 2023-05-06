#include <bits/stdc++.h>
#define fi first
#define se second
#define maxl 18
#define maxn 200001
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

struct node {
	LL sum;
	int l,r,cnt;
	bool lazy;
}ptree[80*maxn];

int T,n,t,id;
LL b[maxn];
int a[maxn];
int p[maxn];
int rp[maxn];
int dt[maxn];
int ft[maxn];
int lvl[maxn];
int ans[maxn];
int tree[4*maxn];
int par[maxn][maxl];
vector<pi> add[maxn];
vector<int> adj[maxn];

void reset() {
	t = 0;
	for( int i = 1 ; i <= id ; i++ ) {
		ptree[i].l = ptree[i].r = 0;
		ptree[i].sum = ptree[i].cnt = 0;
		ptree[i].lazy = false;
	}
	id = 0;
	for( int i = 1 ; i <= 4*n ; i++ )
		tree[i] = 0;
	for( int i = 1 ; i <= n ; i++ ) {
		add[i].clear();
		adj[i].clear();
		for( int j = 0 ; j < maxl ; j++ )
			par[i][j] = 0;
	}
}

void input() {
	scanf("%d",&n);
	for( int i = 1 , u , v ; i < n ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&p[i]);
		rp[p[i]] = i;
	}
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&a[i]);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%lld",&b[i]);
}

int getRoot() {
	return (LL)rand()*rand()%n+1;
}

void dfs1(int u , int dad) {
	dt[u] = ++t;
	lvl[u] = lvl[dad]+1;
	par[u][0] = dad;
	for( int l = 1 ; l < maxl && par[u][l-1] ; l++ )
		par[u][l] = par[par[u][l-1]][l-1];
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v != dad)
			dfs1(v,u);
	}
	ft[u] = t;
}

int query(int tx , int ty , int q , int id) {
	if(ty < q || q < tx)
		return 0;
	if(tx == ty)
		return tree[id];
	int m = (tx+ty) >> 1;
	int d = max( query(tx,m,q,2*id) , query(m+1,ty,q,2*id+1) );
	return max(tree[id],d);
}

void update(int tx , int ty , int qx , int qy , int val , int id) {
	if(ty < qx || qy < tx)
		return;
	if(qx <= tx && ty <= qy) {
		tree[id] = max(tree[id],val);
		return;
	}
	int m = (tx+ty) >> 1;
	update(tx,m,qx,qy,val,2*id);
	update(m+1,ty,qx,qy,val,2*id+1);
}

int findRoot(int u , int diff) {
	for( int i = 0 ; i < maxl ; i++ )
		if(diff & (1<<i))
			u = par[u][i];
	return u;
}

void calcRoots() {
	for( int i = 1 ; i <= n ; i++ ) {
		int u = p[i];
		int d = query(1,n,dt[u],1);
		int rootU = findRoot(u,lvl[u]-d-1);
		add[rootU].pb(pi(i,a[u]));
		update(1,n,dt[u],ft[u],lvl[u],1);
	}
}

void output() {
	for( int i = 1 ; i <= n ; i++ )
		printf("%d ",ans[i]);
	puts("");
}

int newLeaf() {
	int p = ++id;
	ptree[p].l = ptree[p].r = 0;
	ptree[p].sum = ptree[p].cnt = 0;
	ptree[p].lazy = false;
	return p;
}

int newParent(int l , int r) {
	int p = ++id;
	ptree[p].l = l;
	ptree[p].r = r;
	ptree[p].sum = ptree[l].sum + ptree[r].sum;
	return p;
}

int newLazyKid2(int node , int delta) {
	int p = ++id;
	ptree[p].l = ptree[node].l;
	ptree[p].r = ptree[node].r;
	ptree[p].cnt = ptree[node].cnt;
	ptree[p].sum = ptree[node].sum + delta;
	ptree[p].lazy = true;
	return p;
}

int newLazyKid(int node , int delta) {
	int p = ++id;
	ptree[p].l = ptree[node].l;
	ptree[p].r = ptree[node].r;
	ptree[p].cnt = ptree[node].cnt + delta;
	ptree[p].sum = (delta == 0) ? ptree[node].sum : 0;
	ptree[p].lazy = true;
	return p;
}

void propagate(int p , int l , int r) {
	if(ptree[p].lazy) {
		if(l != r) {
			ptree[p].l = newLazyKid(ptree[p].l,ptree[p].cnt);
			ptree[p].r = newLazyKid(ptree[p].r,ptree[p].cnt);
		}
		ptree[p].lazy = false;
	}
}

int updateIgnore(int tx , int ty , int qx , int qy , int p) {
	if(ty < qx || qy < tx)
		return p;
	if(qx <= tx && ty <= qy)
		return newLazyKid(p,1);
	propagate(p,tx,ty);
	int m = (tx+ty) >> 1;
	int l = updateIgnore(tx,m,qx,qy,ptree[p].l);
	int r = updateIgnore(m+1,ty,qx,qy,ptree[p].r);
	return newParent(l,r);
}

int updateAdd(int tx , int ty , int q , int val , int p) {
	if(ty < q || q < tx)
		return p;
	if(tx == ty)
		return newLazyKid2(p,val);
	propagate(p,tx,ty);
	int m = (tx+ty) >> 1;
	int l = updateAdd(tx,m,q,val,ptree[p].l);
	int r = updateAdd(m+1,ty,q,val,ptree[p].r);
	int par = newParent(l,r);
	return par;
}

int queryTime(int x , int y , LL& rem , int p) {
	int l = ptree[p].l;
	int r = ptree[p].r;
	if(ptree[p].sum < rem) {
		rem -= ptree[p].sum;
		return -1;
	}
	else if(x == y)
		return x;
	propagate(p,x,y);
	int m = (x+y) >> 1;
	int res = queryTime(x,m,rem,ptree[p].l);
	if(res != -1)
		return res;
	return queryTime(m+1,y,rem,ptree[p].r);
}

int build(int l , int r) {
	if(l == r)
		return newLeaf();
	int m = (l+r) >> 1;
	return newParent( build(l,m) , build(m+1,r) );
}

void dfs2(int u , int dad , int root) {
	if(rp[u] < n)
		root = updateIgnore(1,n,rp[u]+1,n,root);
	int sz = add[u].size();
	for( int i = 0 ; i < sz ; i++ )
		root = updateAdd(1,n,add[u][i].fi,add[u][i].se,root);
	ans[u] = queryTime(1,n,b[u],root);
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v != dad)
			dfs2(v,u,root);
	}
}

void solve() {
	int root = getRoot();
	dfs1(root,0);
	calcRoots();
	int pRoot = build(1,n);
	dfs2(root,0,pRoot);
}

int main() {
	srand(time(NULL));
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
		output();
	}
	return 0;
}
