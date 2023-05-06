#include <bits/stdc++.h>
#define fi first
#define se second
#define maxt 100001
#define maxn 100001
#define maxm 300001
#define maxe 600001
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

struct testcase {
	int n,m;
	vector<pi> edges;
}inputs[maxt];

int T,tc,n,m,e;
int dfsc;
clock_t startTime;

int to[maxe];
int ans[maxm];
int lvl[maxn];
int par[maxn];
int mark[maxn];
bool forbid[maxn];
int leftEdge[maxe];
int lastEdge[maxn];
int rightEdge[maxe];
int firstEdge[maxn];
int prefixSum[maxt];

vector<int> chain;
pi best[maxn][2];
vector<int> visited;
vector<pi> bests[maxn][2];
map<int,int> edgeId[maxn];

void reset() {
	for( int i = 1 ; i <= n ; i++ )
		forbid[i] = 0;
	for( int i = 1 ; i <= n ; i++ )
		edgeId[i].clear();
	for( int i = 1 ; i <= n ; i++ )
		firstEdge[i] = lastEdge[i] = 0;
	for( int i = 1 ; i <= e ; i++ )
		leftEdge[i] = rightEdge[i] = 0;
	for( int i = 1 ; i <= m ; i++ )
		ans[i] = 0;
	e = 0;
}

void input() {
	scanf("%d",&T);
	for( tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&m);
		inputs[tc].n = n;
		inputs[tc].m = m;
		prefixSum[tc] = prefixSum[tc-1]+n+m;
		for( int i = 0 , u,v ; i < m ; i++ ) {
			scanf("%d%d",&u,&v);
			inputs[tc].edges.pb(pi(u,v));
		}
	}
}

void addEdge(int u , int v) {
	to[++e] = v;
	edgeId[u][v] = e;
	if(firstEdge[u]) {
		int last = lastEdge[u];
		lastEdge[u] = e;
		leftEdge[e] = last;
		rightEdge[last] = e;
	}
	else
		firstEdge[u] = lastEdge[u] = e;
}

void removeEdge(int u , int v , int sign) {
	int id = edgeId[u][v];
	ans[(id+1)/2] = sign;
	edgeId[u].erase(v);
	int l = leftEdge[id];
	int r = rightEdge[id];
	if(l == 0)
		firstEdge[u] = r;
	else
		rightEdge[l] = r;
	if(r == 0)
		lastEdge[u] = l;
	else
		leftEdge[r] = l;
}

void removeChain() {
	int sz = chain.size();
	for( int i = 1 , sign = -1 ; i < sz ; i++ , sign = -sign ) {
		int u = chain[i-1];
		int v = chain[i];
		removeEdge(u,v,sign);
		removeEdge(v,u,sign);
	}
	int src = chain[0];
	int dest = chain[sz-1];
	removeEdge(src,dest,1);
	removeEdge(dest,src,1);
}

void testcase() {
	n = inputs[tc].n;
	m = inputs[tc].m;
	for( int i = 0 , u,v ; i < m ; i++ ) {
		u = inputs[tc].edges[i].fi;
		v = inputs[tc].edges[i].se;
		addEdge(u,v);
		addEdge(v,u);
	}
}

void dfs(int u , int dad) {
	bests[u][0].clear();
	bests[u][1].clear();
	visited.pb(u);
	par[u] = dad;
	mark[u] = dfsc;
	lvl[u] = lvl[dad]+1;
	int id = firstEdge[u];
	while(id) {
		int v = to[id];
		if(v == dad);
		else if(mark[v] != dfsc) {
			best[u][0] = best[u][1] = pi(0,0);
			dfs(v,u);
			if(best[u][0].fi)
				bests[u][0].pb(best[u][0]);
			if(best[u][1].fi)
				bests[u][1].pb(best[u][1]);
		}
		else if(lvl[v] < lvl[u]) {
			int diff = lvl[u]-lvl[v]+1;
			int type = (diff&1);
			if(diff > 1 && diff > best[v][type].se)
				best[v][type] = pi(u,diff);
		}
		id = rightEdge[id];
	}
}

void forbidNodes() {
	int sz = visited.size();
	for( int i = 0 ; i < sz ; i++ )
		forbid[visited[i]] = true;
}

bool checkChain() {
	int bestSum = 0;
	int bestNode = -1;
	int bestType = -1;
	int bestIdx = -1;
	int sz = visited.size();
	for( int i = 0 ; i < sz ; i++ ) {
		int u = visited[i];
		int sz0 = bests[u][0].size() , sum0 = 0;
		if(sz0)
			for( int j = 0 ; j < sz0 ; j++ )
				sum0 += bests[u][0][j].se;
		int sz1 = bests[u][1].size() , sum1 = 0 , idx = -1;
		if(sz1 >= 2)
			for( int j = 0 ; j < sz1 ; j++ ) {
				if(idx == -1 || bests[u][1][j].se < bests[u][1][idx].se)
					idx = j;
				sum1 += bests[u][1][j].se;
			}
		if(sz1 <= 1)
			sum1 = 0;
		else if(sz1%2)
			sum1 -= bests[u][1][idx].se;
		else
			idx = -1;
		int maxSum = max(sum0,sum1);
		if(maxSum > bestSum) {
			bestSum = maxSum;
			bestNode = u;
			bestType = (sum0 >= sum1) ? 0 : 1;
			bestIdx = idx;
		}
	}
	if(bestSum == 0)
		return false;
	chain.clear();
	int u = bestNode;
	if(bestType == 0) {
		int sz = bests[u][0].size();
		for( int i = 0 ; i < sz ; i++ ) {
			int v = bests[u][0][i].fi;
			while(v != u) {
				chain.pb(v);
				v = par[v];
			}
			chain.pb(u);
		}
		reverse(chain.begin(),chain.end());
		chain.pb(u);
	}
	else {
		int sz = bests[u][1].size();
		for( int i = 0 ; i < sz ; i++ )
			if(i != bestIdx) {
				int v = bests[u][1][i].fi;
				while(v != u) {
					chain.pb(v);
					v = par[v];
				}
				chain.pb(u);
			}
		reverse(chain.begin(),chain.end());
		chain.pb(u);
	}
	return true;
}

void findChain(int u) {
	visited.clear();
	dfsc++;
	dfs(u,0);
	if(checkChain())
		removeChain();
	else
		forbidNodes();
}

void solve() {
	vector<int> nodes;
	for( int i = 1 ; i <= n ; i++ )
		nodes.pb(i);
	reverse(nodes.begin(),nodes.end());
	random_shuffle(nodes.begin(),nodes.end());
	while(!nodes.empty()) {
		double ratio = (double) prefixSum[tc] / prefixSum[T];
		double lim = 6.0 * ratio - 0.1;
		double dur = double(clock()-startTime) / CLOCKS_PER_SEC;
		if(dur >= lim)
			break;
		int u = nodes.back();
		if(forbid[u])
			nodes.pop_back();
		else
			findChain(u);
	}
}

void output() {
	for( int i = 1 ; i <= m ; i++ )
		printf("%d\n",ans[i]);
}

int main() {
	startTime = clock();
	srand(time(NULL));
	input();
	for( tc = 1 ; tc <= T ; tc++ ) {
		reset();
		testcase();
		solve();
		output();
	}
	return 0;
}
