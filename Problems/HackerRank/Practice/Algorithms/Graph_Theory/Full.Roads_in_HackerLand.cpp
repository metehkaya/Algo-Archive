#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100003
#define maxm 200003
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

int n,m;
int dad[maxn];
int lvl[maxn];
pi edge[maxm];
vector<int> ans;
vector<pi> adj[maxn];

int find(int u) {
	if(u == dad[u])
		return u;
	return dad[u] = find(dad[u]);
}

void addValue(int w, int add) {
	if( (int) ans.size() < w+1 )
		ans.resize(w+1);
	ans[w] += add;
}

void addEdge(int w, LL mult) {
	for( int i = 0 ; i < 35 ; i++ )
		if( mult & (1LL << i) )
			addValue(w+i, 1);
}

int dfs(int node, int par) {
	int cnt = 1;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i].fi;
		int w = adj[node][i].se;
		if( to != par ) {
			int add = dfs(to, node);
			LL mult = (LL) add * (n-add);
			addEdge(w, mult);
			cnt += add;
		}
	}
	return cnt;
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x,y,z ; i < m ; i++ ) {
		scanf("%d%d%d",&x,&y,&z);
		edge[z] = pi(x,y);
	}
	for( int i = 1 ; i <= n ; i++ )
		dad[i] = i;
	for( int i = 0 ; i < m ; i++ ) {
		int x = edge[i].fi;
		int y = edge[i].se;
		int X = find(x);
		int Y = find(y);
		if( X != Y ) {
			adj[x].pb(pi(y,i));
			adj[y].pb(pi(x,i));
			if(lvl[Y] < lvl[X])
				swap(X,Y);
			dad[X] = Y;
			if(lvl[X] == lvl[Y])
				lvl[Y]++;
		}
	}
	dfs(1,0);
	for( int i = 0 ; i < (int) ans.size() ; i++ ) {
		int val = ans[i];
		if(val > 1) {
			ans[i] %= 2;
			addValue(i+1, val/2);
		}
	}
	for( int i = (int) ans.size() - 1 ; i >= 0 ; i-- )
		printf("%d",ans[i]);
	return 0;
}
