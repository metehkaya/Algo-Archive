#include <bits/stdc++.h>
#define fi first
#define se second
#define maxk 17
#define maxn 100003
#define maxK (1<<maxk)
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int ans,K;
int n,m,k;
int c[maxk];
int revc[maxn];
bool mark[maxn];
int d[maxk][maxk];
int dp[maxk][maxK];
vector<int> adj[maxn];

void bfs(int root) {
	queue<pi> Q;
	memset(mark,false,sizeof(mark));
	mark[root] = true;
	Q.push(pi(root,0));
	while(!Q.empty()) {
		pi temp = Q.front();
		Q.pop();
		int u = temp.fi;
		int dist = temp.se;
		if(revc[u] != -1)
			d[revc[root]][revc[u]] = dist;
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			if(!mark[v]) {
				mark[v] = true;
				Q.push(pi(v,dist+1));
			}
		}
	}
}

int f(int u , int bmask) {
	if(bmask == K-1)
		return dp[u][bmask] = 0;
	if(dp[u][bmask] != -1)
		return dp[u][bmask];
	dp[u][bmask] = INT_MAX;
	for( int i = 0 ; i < k ; i++ )
		if(d[u][i] != -1 && (bmask&(1<<i)) == 0) {
			int temp = f(i,(bmask|(1<<i)));
			if(temp != INT_MAX)
				dp[u][bmask] = min(dp[u][bmask],temp+d[u][i]);
		}
	return dp[u][bmask];
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , u,v ; i < m ; i++ ) {
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	scanf("%d",&k);
	K = (1<<k);
	memset(revc,-1,sizeof(revc));
	for( int i = 0 ; i < k ; i++ ) {
		scanf("%d",&c[i]);
		revc[c[i]] = i;
	}
	memset(d,-1,sizeof(d));
	for( int i = 0 ; i < k ; i++ )
		bfs(c[i]);
	ans = INT_MAX;
	memset(dp,-1,sizeof(dp));
	for( int i = 0 ; i < k ; i++ )
		ans = min(ans,f(i,(1<<i)));
	ans = (ans == INT_MAX) ? -1 : ans+1;
	printf("%d\n",ans);
	return 0;
}
