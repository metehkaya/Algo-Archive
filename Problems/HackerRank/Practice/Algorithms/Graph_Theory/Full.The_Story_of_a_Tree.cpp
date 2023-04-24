#include <bits/stdc++.h>
#define maxn 100003
#define pb push_back
using namespace std;

int T,n,g,k,cnt,ans;
set<int> guess[maxn];
vector<int> adj[maxn];

void reset() {
	ans = cnt = 0;
	for( int i = 1 ; i <= n ; i++ ) {
		adj[i].clear();
		guess[i].clear();
	}
}

void input() {
	scanf("%d",&n);
	for( int i = 1 , x , y ; i < n ; i++ ) {
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	scanf("%d%d",&g,&k);
	for( int i = 0 , u , v ; i < g ; i++ ) {
		scanf("%d%d",&u,&v);
		guess[u].insert(v);
	}
}

void dfs1(int node , int dad) {
	for( int i = 0 ; i < adj[node].size() ; i++ )
		if(adj[node][i] != dad) {
			if(guess[node].count(adj[node][i]))
				cnt++;
			dfs1(adj[node][i],node);
		}
}

void dfs2(int node , int dad , int cnt) {
	if(cnt >= k)
		ans++;
	for( int i = 0 ; i < adj[node].size() ; i++ )
		if(adj[node][i] != dad)
			dfs2( adj[node][i] , node , cnt - guess[node].count( adj[node][i] ) + guess[ adj[node][i] ].count(node) );
}

int gcd( int a , int b ) {
	if(!b)
		return a;
	return gcd(b,a%b);
}

void output() {
	int GCD = gcd(ans,n);
	printf("%d/%d\n",ans/GCD,n/GCD);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		dfs1(1,0);
		dfs2(1,0,cnt);
		output();
	}
	return 0;
}
