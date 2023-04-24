#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 2001
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

struct data {
	int to,len,dec;
};

bool operator<(const data &a , const data &b) {
	if(a.len != b.len)
		return a.len > b.len;
	return a.dec > b.dec;
}

data getData(int _to , int _len , int _dec) {
	data d;
	d.to = _to;
	d.len = _len;
	d.dec = _dec;
	return d;
}

int n,m,k,t,ans;
int cost[maxn];
int mark[maxn][maxn];
pi dist[maxn][maxn];
pii pre[maxn][maxn];
vector<pi> adj[maxn];

void read() {
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for( int i = 0 , x , y ; i < m ; i++ ) {
		scanf("%d%d",&x,&y);
		adj[x].pb(pi(y,i));
		adj[y].pb(pi(x,i));
	}
}

data sssp(int tc) {
	priority_queue<data> heap;
	dist[0][0] = pi(0,tc);
	heap.push(getData(0,0,0));
	while(!heap.empty()) {
		data d = heap.top();
		heap.pop();
		int node = d.to;
		int length = d.len;
		int decrease = d.dec;
		if(mark[node][decrease] == tc)
			continue;
		if(node == n-1)
			return d;
		mark[node][decrease] = tc;
		for( int i = 0 ; i < adj[node].size() ; i++ ) {
			int to = adj[node][i].fi;
			int id = adj[node][i].se;
			if(mark[to][decrease] == tc)
				continue;
			if(dist[to][decrease].se == tc && max(length,cost[id]) >= dist[to][decrease].fi)
				continue;
			dist[to][decrease] = pi(max(length,cost[id]),tc);
			pre[to][decrease] = pii(pi(node,decrease),id);
			heap.push( getData(to,max(length,cost[id]),decrease));
			if(decrease == t || cost[id] == 0)
				continue;
			if(mark[to][decrease+1] == tc)
				continue;
			if(dist[to][decrease+1].se == tc && max(length,cost[id]-1) >= dist[to][decrease+1].fi)
				continue;
			dist[to][decrease+1] = pi(max(length,cost[id]-1),tc);
			pre[to][decrease+1] = pii(pi(node,decrease),id);
			heap.push( getData(to,max(length,cost[id]-1),decrease+1));
		}
	}
	return getData(-1,-1,-1);
}

void modify(int tc , data d) {
	int node = d.to;
	int length = d.len;
	int decrease = d.dec;
	ans = max(ans,length);
	t -= decrease;
	while(node != 0) {
		pii prev = pre[node][decrease];
		int prevNode = prev.fi.fi;
		int prevDecrease = prev.fi.se;
		int prevId = prev.se;
		if(decrease == prevDecrease)
			cost[prevId]++;
		node = prevNode;
		decrease = prevDecrease;
	}
}

void solve() {
	ans = 0;
	for( int tc = 1 ; tc <= k ; tc++ ) {
		data d = sssp(tc);
		modify(tc,d);
	}
	printf("%d\n",ans);
}

int main() {
	read();
	solve();
	return 0;
}
