#include <bits/stdc++.h>
#define maxn 50003
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

struct query {
	int u,d,k,id;
} q[maxn];

bool comp(query a , query b) {
	if(a.u != b.u)
		return a.u < b.u;
	return a.d < b.d;
}

int n,m,qid;
int v[maxn];
int res[maxn];
int mark[maxn];
pi val[maxn];
pi tree[4*maxn];
vector<int> adj[maxn];

void read() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&val[i].fi);
		val[i].se = i;
	}
	for( int i = 1 , x , y ; i < n ; i++ ) {
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	scanf("%d",&m);
	for( int i = 1 ; i <= m ; i++ ) {
		scanf("%d%d%d",&q[i].u,&q[i].d,&q[i].k);
		q[i].id = i;
	}
}

int query(int x , int y , int &k , int root , int id) {
	if(tree[id].se != root)
		tree[id] = pi(0,root);
	if(k > tree[id].fi) {
		k -= tree[id].fi;
		return -1;
	}
	if(x == y)
		return x;
	int mid = (x+y) >> 1;
	int left = query(x,mid,k,root,id*2);
	if(left != -1)
		return left;
	return query(mid+1,y,k,root,id*2+1);
}

void update(int cx , int cy , int q , int root , int id) {
	if(tree[id].se != root)
		tree[id] = pi(0,root);
	if(cy < q || q < cx)
		return;
	tree[id].fi++;
	if(cx == cy)
		return;
	int mid = (cx+cy) >> 1;
	update(cx,mid,q,root,id*2);
	update(mid+1,cy,q,root,id*2+1);
}

void bfs( int root ) {
	queue<pi> que;
	mark[root] = root;
	que.push(pi(root,0));
	while(!que.empty()) {
		pi tmp = que.front();
		que.pop();
		int node = tmp.fi;
		int dist = tmp.se;
		while(qid <= m && q[qid].u == root && dist > q[qid].d) {
			res[q[qid].id] = query(1,n,q[qid].k,root,1);
			qid++;
		}
		if(qid > m || q[qid].u != root)
			break;
		update(1,n,v[node],root,1);
		for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
			int to = adj[node][i];
			if(mark[to] == root)
				continue;
			mark[to] = root;
			que.push(pi(to,dist+1));
		}
	}
	while(qid <= m && q[qid].u == root) {
		res[q[qid].id] = query(1,n,q[qid].k,root,1);
		qid++;
	}
}

void solve() {
	sort(val+1,val+n+1);
	for( int i = 1 ; i <= n ; i++ )
		v[val[i].se] = i;
	sort(q+1,q+m+1,comp);
	qid = 1;
	while(qid <= m)
		bfs(q[qid].u);
}

void print() {
	for( int i = 1 ; i <= m ; i++ ) {
		if(res[i] != -1)
			res[i] = val[res[i]].fi;
		printf("%d\n",res[i]);
	}
}

int main() {
	read();
	solve();
	print();
	return 0;
}
