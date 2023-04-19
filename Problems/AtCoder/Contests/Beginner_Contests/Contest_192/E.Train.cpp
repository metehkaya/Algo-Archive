#include <bits/stdc++.h>
#define maxn 100003
#define pb push_back
using namespace std;
typedef long long LL;

struct datum {
	int to,k;
	LL dist;
};

datum getDatum(int _to , LL _dist , int _k) {
	datum d;
	d.to = _to;
	d.dist = _dist;
	d.k = _k;
	return d;
}

bool operator<(const datum& a , const datum& b) {
	return a.dist > b.dist;
}

int n,m,x,y;
bool mark[maxn];
vector<datum> adj[maxn];
priority_queue<datum> heap;

int main() {
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for( int i = 0 , u,v,d,k ; i < m ; i++ ) {
		scanf("%d%d%d%d",&u,&v,&d,&k);
		adj[u].pb(getDatum(v,d,k));
		adj[v].pb(getDatum(u,d,k));
	}
	heap.push(getDatum(x,0,-1));
	while(!heap.empty()) {
		datum d = heap.top();
		heap.pop();
		int u = d.to;
		LL dist = d.dist;
		int k = d.k;
		if(mark[u])
			continue;
		if(u == y) {
			printf("%lld\n",dist);
			return 0;
		}
		mark[u] = true;
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i].to;
			int c = adj[u][i].dist;
			int k2 = adj[u][i].k;
			if(mark[v])
				continue;
			LL cost = dist;
			if(cost % k2)
				cost += k2 - cost%k2;
			cost += c;
			heap.push(getDatum(v,cost,-1));
		}
	}
	puts("-1");
	return 0;
}
