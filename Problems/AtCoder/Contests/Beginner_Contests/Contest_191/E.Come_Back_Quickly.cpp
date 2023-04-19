#include <bits/stdc++.h>
#define maxn 2001
#define pb push_back
using namespace std;

struct node {
	int u,d;
	node(int _u , int _d) {
		u = _u;
		d = _d;
	}
};

bool operator<(const node& a , const node& b) {
	return a.d > b.d;
}

int n,m;
int dist[maxn];
bool mark[maxn];
vector<node> adj[maxn];

int sssp(int root) {
	int res = -1;
	priority_queue<node> pq;
	pq.push(node(root,0));
	memset(dist,-1,sizeof(dist));
	memset(mark,false,sizeof(mark));
	dist[root] = 0;
	while(!pq.empty()) {
		node temp = pq.top();
		pq.pop();
		int u = temp.u;
		int d = temp.d;
		if(mark[u])
			continue;
		mark[u] = true;
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i].u;
			int d2 = d + adj[u][i].d;
			if(v == root) {
				if(res == -1 || d2 < res)
					res = d2;
			}
			if(!mark[v] && (dist[v] == -1 || d2 < dist[v])) {
				dist[v] = d2;
				pq.push(node(v,d2));
			}
		}
	}
	return res;
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , u,v,d ; i < m ; i++ ) {
		scanf("%d%d%d",&u,&v,&d);
		adj[u].pb(node(v,d));
	}
	for( int i = 1 ; i <= n ; i++ )
		printf("%d\n",sssp(i));
	return 0;
}
