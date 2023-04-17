#include <bits/stdc++.h>
#define maxn 100003
#define pb push_back
using namespace std;

int n;
int src,maxDist;
int sink,ansDist;
int par[maxn];
vector<int> adj[maxn];

void dfs(int u , int dad , int dist , bool firstStage) {
	if(firstStage) {
		if(dist > maxDist)
			maxDist = dist , src = u;
	}
	else {
		par[u] = dad;
		if(dist > ansDist)
			ansDist = dist , sink = u;
	}
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v != dad)
			dfs(v,u,dist+1,firstStage);
	}
}

void printChain() {
	printf("Chain:");
	int u = sink;
	while(u != src) {
		printf(" %d",u);
		u = par[u];
	}
	printf(" %d\n",src);
}

int main() {
	scanf("%d",&n);
	for( int i = 1 , u,v ; i < n ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	maxDist = -1;
	dfs(1,0,0,true);
	ansDist = -1;
	dfs(src,0,0,false);
	printf("Diameter = %d\n",ansDist);
	printChain();
	return 0;
}
