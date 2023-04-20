#include <bits/stdc++.h>
#define maxn 200001
#define pb push_back
using namespace std;

int n;
int best,mxDist;
vector<int> adj[maxn];

void dfs(int u , int dad , int dist) {
	if(dist >= mxDist) {
		best = u;
		mxDist = dist;
	}
	for( int i = 0 ; i < (int) adj[u].size() ; i++ ) {
		int v = adj[u][i];
		if(v == dad)
			continue;
		dfs(v,u,dist+1);
	}
}

int main() {
	scanf("%d",&n);
	for( int i = 1 , u,v ; i < n ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0,0);
	mxDist = 0;
	dfs(best,0,0);
	printf("%d\n",mxDist);
	return 0;
}