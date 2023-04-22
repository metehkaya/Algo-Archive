#include <bits/stdc++.h>
#define maxn 200001
#define pb push_back
using namespace std;
typedef long long LL;

int T,n,m,a,b,t;
int Q[maxn];
int dt[maxn];
int ft[maxn];
int rev[maxn];
int cnt[maxn];
int idx[maxn];
int tree[4*maxn];
vector<int> adj[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	t = 0;
	memset(cnt,0,sizeof(cnt));
	memset(idx,0,sizeof(idx));
	for( int i = 0 ; i < n ; i++ )
		adj[i].clear();
}

void bfs() {
	int l = 0 , r = 0;
	Q[r++] = 0;
	while(l < r) {
		int u = Q[l++];
		for( int i = 0 ; i < adj[u].size() ; i++ )
			Q[r++] = adj[u][i];
	}
}

void dfs() {
	stack<int> st;
	st.push(0);
	while(!st.empty()) {
		int u = st.top();
		if(idx[u] == 0) {
			dt[u] = t;
			rev[t++] = u;
		}
		if(idx[u] < adj[u].size())
			st.push(adj[u][idx[u]++]);
		else {
			st.pop();
			ft[u] = t-1;
		}
	}
}

int init(int x , int y , int id) {
	if(x == y)
		return tree[id] = rev[x];
	int mid = (x + y) >> 1;
	int l = init(x,mid,2*id+1);
	int r = init(mid+1,y,2*id+2);
	return tree[id] = max(l,r);
}

int query(int cx , int cy , int qx , int qy , int id) {
	if(cy < qx || qy < cx)
		return -1;
	if(qx <= cx && cy <= qy)
		return tree[id];
	int mid = (cx + cy) >> 1;
	int l = query(cx,mid,qx,qy,2*id+1);
	int r = query(mid+1,cy,qx,qy,2*id+2);
	return max(l,r);
}

int update(int cx , int cy , int q , int id) {
	if(cy < q || q < cx)
		return tree[id];
	if(cx == cy)
		return tree[id] = -1;
	int mid = (cx + cy) >> 1;
	int l = update(cx,mid,q,2*id+1);
	int r = update(mid+1,cy,q,2*id+2);
	return tree[id] = max(l,r);
}

LL solve() {
	LL ans = 0;
	init(0,n-1,0);
	for( int i = n-1 ; i >= 0 ; i-- ) {
		int u = Q[i];
		for( int j = 0 ; j < cnt[u] ; j++ ) {
			int v = query(0,n-1,dt[u],ft[u],0);
			if(v == -1)
				break;
			ans += v;
			update(0,n-1,dt[v],0);
		}
	}
	return ans;
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d%d%d",&n,&m,&a,&b);
		for( int i = 1 , u ; i < n ; i++ ) {
			scanf("%d",&u);
			adj[u].pb(i);
		}
		for( int i = 0 ; i < m ; i++ ) {
			LL x = (LL) a*i+b;
			cnt[x%n]++;
		}
		dfs();
		bfs();
		printf("Case #%d: %lld\n",tc,solve());
	}
	return 0;
}
