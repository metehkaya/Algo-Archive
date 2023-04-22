#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 1000001
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,LL> piLL;

int T,n,k,s,e;
int ar[maxn];
int dad[maxn];
int dist[maxn];
LL tree[8*maxn];
vector<int> chain;
vector<int> adj[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	chain.clear();
	memset(dad,-1,sizeof(dad));
	memset(tree,-1,sizeof(tree));
	memset(dist,-1,sizeof(dist));
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
}

void getChain() {
	queue<int> Q;
	Q.push(s);
	dad[s] = 0;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for( int i = 0 ; i < adj[u].size() ; i++ ) {
			int v = adj[u][i];
			if(dad[v] == -1) {
				Q.push(v);
				dad[v] = u;
			}
		}
	}
	int u = e;
	chain.pb(u);
	while(u != s) {
		u = dad[u];
		chain.pb(u);
	}
	reverse(chain.begin(),chain.end());
}

void bfs(int u , int x , int y , vector<int>& nodes) {
	queue<int> Q;
	Q.push(u);
	dist[u] = 0;
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		nodes.pb(u);
		for( int i = 0 ; i < adj[u].size() ; i++ ) {
			int v = adj[u][i];
			if(v != x && v != y && dist[v] == -1) {
				Q.push(v);
				dist[v] = dist[u]+1;
			}
		}
	}
}

void update(int cx , int cy , int q , LL val , int id) {
	if(q < cx || cy < q)
		return;
	if(tree[id] == -1 || val < tree[id])
		tree[id] = val;
	if(cx == cy)
		return;
	int mid = (cx + cy) >> 1;
	update(cx,mid,q,val,id*2);
	update(mid+1,cy,q,val,id*2+1);
}

LL query(int cx , int cy , int qx , int qy , int id) {
	if(qy < cx || cy < qx)
		return -1;
	if(qx <= cx && cy <= qy)
		return tree[id];
	int mid = (cx + cy) >> 1;
	LL l = query(cx,mid,qx,qy,id*2);
	LL r = query(mid+1,cy,qx,qy,id*2+1);
	if(l == -1 && r == -1)
		return -1;
	else if(l == -1)
		return r;
	else if(r == -1)
		return l;
	return min(l,r);
}

LL solve() {
	update(0,2*n-1,n,0,1);
	int len = chain.size();
	for( int d = 1 ; d < len-1 ; d++ ) {
		int root = chain[d];
		int x = chain[d-1];
		int y = chain[d+1];
		vector<int> nodes;
		bfs(root,x,y,nodes);
		vector<piLL> updTree;
		for( int i = 0 ; i < nodes.size() ; i++ ) {
			int u = nodes[i];
			if(ar[u]) {
				int p = dist[u];
				if(p < k) {
					int l = n+d+p-k;
					int r = n+d-1;
					if(l <= r) {
						LL val = query(0,2*n-1,l,r,1);
						if(val != -1)
							updTree.pb(piLL(n+d-p,val+ar[u]));
					}
				}
			}
		}
		for( int i = 0 ; i < updTree.size() ; i++ )
			update(0,2*n-1,updTree[i].fi,updTree[i].se,1);
	}
	return query(0,2*n-1,n+len-1-k,n+len-2,1);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d%d%d",&n,&k,&s,&e);
		for( int i = 1 , p ; i <= n ; i++ ) {
			scanf("%d%d",&p,&ar[i]);
			if(p) {
				adj[i].pb(p);
				adj[p].pb(i);
			}
		}
		getChain();
		printf("Case #%d: %lld\n",tc,solve());
	}
	return 0;
}
