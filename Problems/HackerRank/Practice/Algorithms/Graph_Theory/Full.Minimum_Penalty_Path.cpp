#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 1003
#define maxc 1024
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n,m,s,e;
bool mark[maxn][maxc];
vector<pi> adj[maxn];

void dfs(int node, int value) {
	mark[node][value] = true;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i].fi;
		int len = value | adj[node][i].se;
		if(!mark[to][len])
			dfs(to,len);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x,y,z ; i < m ; i++ ) {
		scanf("%d%d%d",&x,&y,&z);
		adj[x].pb(pi(y,z));
		adj[y].pb(pi(x,z));
	}
	scanf("%d%d",&s,&e);
	dfs(s,0);
	int res = -1;
	for( int i = 0 ; i < maxc ; i++ )
		if( mark[e][i] ) {
			res = i;
			break;
		}
	printf("%d\n",res);
	return 0;
}
