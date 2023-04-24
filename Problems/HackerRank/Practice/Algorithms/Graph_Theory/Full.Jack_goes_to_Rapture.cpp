#include <bits/stdc++.h>
#define maxn 50003
#define pb push_back
using namespace std;
typedef long long LL;

struct data {
	int to,dist;
};

data getData(int _to, int _dist) {
	data d;
	d.to = _to;
	d.dist = _dist;
	return d;
}

bool operator<(const data &a, const data &b) {
	return a.dist > b.dist;
}

int n,m;
bool mark[maxn];
vector<data> adj[maxn];
priority_queue<data> heap;

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x,y,z ; i < m ; i++ ) {
		scanf("%d%d%d",&x,&y,&z);
		adj[x].pb(getData(y,z));
		adj[y].pb(getData(x,z));
	}
	heap.push(getData(1,0));
	while(!heap.empty()) {
		data d = heap.top();
		heap.pop();
		int node = d.to;
		int dist = d.dist;
		if(mark[node])
			continue;
		mark[node] = true;
		if(node == n) {
			printf("%d\n",dist);
			break;
		}
		for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
			int to = adj[node][i].to;
			int edge = adj[node][i].dist;
			if(!mark[to])
				heap.push(getData(to, max(dist,edge)));
		}
	}
	if(!mark[n])
		puts("NO PATH EXISTS");
	return 0;
}
