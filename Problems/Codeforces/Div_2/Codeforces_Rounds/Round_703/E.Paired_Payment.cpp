#include <bits/stdc++.h>
#define fi first
#define se second
#define maxc 51
#define maxn 100001
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

struct datum {
	int u,k,dist;
};

bool operator<(const datum& a , const datum& b) {
	return a.dist > b.dist;
}

datum getDatum(int _u , int _k , int _dist) {
	datum d;
	d.u = _u;
	d.k = _k;
	d.dist = _dist;
	return d;
}

int n,m;
int ans[maxn];
bool mark[maxn][maxc];
vector<pi> adj[maxn];
priority_queue<datum> heap;

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , u,v,d ; i < m ; i++ ) {
		scanf("%d%d%d",&u,&v,&d);
		adj[u].pb(pi(v,d));
		adj[v].pb(pi(u,d));
	}
	memset(ans,-1,sizeof(ans));
	heap.push(getDatum(1,0,0));
	while(!heap.empty()) {
		datum dat = heap.top();
		heap.pop();
		int u = dat.u;
		int k = dat.k;
		int d = dat.dist;
		if(mark[u][k])
			continue;
		if(k == 0 && ans[u] == -1)
			ans[u] = d;
		mark[u][k] = true;
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i].fi , k2 , d2;
			int add = adj[u][i].se;
			if(k == 0) {
				k2 = add;
				d2 = d + add*add;
			}
			else {
				k2 = 0;
				d2 = d + add*add + 2*add*k;
			}
			if(!mark[v][k2])
				heap.push(getDatum(v,k2,d2));
		}
	}
	for( int i = 1 ; i <= n ; i++ )
		printf("%d ",ans[i]);
	return 0;
}
