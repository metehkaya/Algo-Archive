#include <bits/stdc++.h>
#define maxn 53
#define inf (1<<30)
using namespace std;
typedef pair<int,int> pi;

int T,n,h,s,e,k;
int x[maxn];
int a[maxn];
int b[maxn];
int p[2*maxn];
int par[maxn];
int G[maxn][maxn];
map<int,int> idx;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	k = 0;
	idx.clear();
	memset(G,0,sizeof(G));
}

bool checkImp() {
	for( int i = 1 ; i <= n ; i++ )
		if(a[i] == 0 && b[i] == h)
			return true;
	return false;
}

void checkSE() {
	s = e = -1;
	for( int i = 1 ; i <= n ; i++ )
		if(x[i] == 0) {
			if(a[i] == 0)
				s = i;
			if(b[i] == h)
				e = i;
		}
	if(s == -1) {
		s = ++n;
		x[s] = a[s] = b[s] = 0;
	}
	if(e == -1) {
		e = ++n;
		x[e] = 0 , a[e] = b[e] = h;
	}
}

void hashh() {
	set<int> s;
	for( int i = 1 ; i <= n ; i++ ) {
		s.insert(a[i]);
		s.insert(b[i]);
	}
	set<int>::iterator it;
	for( it = s.begin() ; it != s.end() ; it++ ) {
		idx[(*it)] = ++k;
		p[k] = (*it);
	}
}

void build() {
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= n ; j++ )
			if(x[i] < x[j]) {
				int mxa = max(a[i],a[j]);
				int mnb = min(b[i],b[j]);
				if(mxa == 0 || mnb == h)
					G[i][j] = G[j][i] = inf;
				else if(mxa < mnb) {
					vector<bool> mark(k+1,false);
					int idxa = idx[mxa];
					int idxb = idx[mnb];
					for( int l = 1 ; l <= n ; l++ )
						if(x[i] < x[l] && x[l] < x[j]) {
							int aa = idx[a[l]];
							int bb = idx[b[l]];
							while(aa < bb)
								mark[aa++] = true;
						}
					int total = 0;
					for( int l = idxa ; l < idxb ; l++ )
						if(!mark[l])
							total += p[l+1] - p[l];
					G[i][j] = G[j][i] = total;
				}
			}
}

int bfs() {
	queue<pi> Q;
	vector<bool> mark(n+1,false);
	mark[s] = true;
	Q.push(pi(s,inf));
	while(!Q.empty()) {
		pi temp = Q.front();
		Q.pop();
		int u = temp.first;
		int d = temp.second;
		if(u == e)
			return d;
		for( int i = 1 ; i <= n ; i++ )
			if(G[u][i] && !mark[i]) {
				int d2 = min(d,G[u][i]);
				par[i] = u;
				mark[i] = true;
				Q.push(pi(i,d2));
			}
	}
	return 0;
}

int solve() {
	int ans = 0 , path = bfs();
	while(path) {
		ans += path;
		int u = e;
		while(u != s) {
			int dad = par[u];
			G[dad][u] -= path;
			G[u][dad] += path;
			u = dad;
		}
		path = bfs();
	}
	return ans;
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&h);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d%d%d",&x[i],&a[i],&b[i]);
		if(checkImp()) {
			printf("Case #%d: -1\n",tc);
			continue;
		}
		checkSE();
		hashh();
		build();
		printf("Case #%d: %d\n",tc,solve());
	}
	return 0;
}
