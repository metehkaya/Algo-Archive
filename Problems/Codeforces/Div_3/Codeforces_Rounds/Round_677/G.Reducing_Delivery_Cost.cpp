#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 1001
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

struct node {
	int u,d;
};

node newNode(int u , int d) {
	node a;
	a.u = u;
	a.d = d;
	return a;
}

bool operator<(const node &a , const node& b) {
	return a.d > b.d;
}

const int MAXD = (1<<30);

int n,m,k,ans;
vector<pi> edges;
vector<pi> paths;
vector<pi> adj[maxn];
int dist[maxn][maxn];
bool mark[maxn][maxn];

void dijkstra(int src) {
	priority_queue<node> heap;
	for( int i = 1 ; i <= n ; i++ )
		dist[src][i] = MAXD;
	dist[src][src] = 0;
	heap.push(newNode(src,0));
	while(!heap.empty()) {
		node temp = heap.top();
		heap.pop();
		int u = temp.u;
		int d = temp.d;
		if(mark[src][u])
			continue;
		mark[src][u] = true;
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i].fi;
			int w = adj[u][i].se;
			if(!mark[src][v] && dist[src][u]+w < dist[src][v]) {
				dist[src][v] = dist[src][u]+w;
				heap.push(newNode(v,dist[src][u]+w));
			}
		}
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 0 , x,y,z ; i < m ; i++ ) {
		scanf("%d%d%d",&x,&y,&z);
		edges.pb(pi(x,y));
		adj[x].pb(pi(y,z));
		adj[y].pb(pi(x,z));
	}
	for( int i = 0 , x,y ; i < k ; i++ ) {
		scanf("%d%d",&x,&y);
		paths.pb(pi(x,y));
	}
	for( int i = 1 ; i <= n ; i++ )
		dijkstra(i);
	ans = MAXD;
	for( int i = 0 ; i < m ; i++ ) {
		int total = 0;
		int a = edges[i].fi;
		int b = edges[i].se;
		for( int j = 0 ; j < k ; j++ ) {
			int x = paths[j].fi;
			int y = paths[j].se;
			int add = dist[x][y];
			add = min(add,dist[x][a]+dist[b][y]);
			add = min(add,dist[x][b]+dist[a][y]);
			total += add;
		}
		ans = min(ans,total);
	}
	printf("%d\n",ans);
	return 0;
}
