#include <bits/stdc++.h>
#define maxk 31
#define maxn 1001
#define pb push_back
using namespace std;

int T,n,k,p;
int dad[maxn];
int ar[maxn][maxk];
int cost[maxk][maxk];
int best[maxn][maxk];
int dp[maxn][maxk][maxk];
vector<int> Q;
vector<int> adj[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	Q.clear();
	memset(dad,-1,sizeof(dad));
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
}

void bfs() {
	Q.pb(1);
	dad[1] = 0;
	for( int i = 0 ; i < n ; i++ ) {
		int u = Q[i];
		for( int j = 0 ; j < adj[u].size() ; j++ ) {
			int v = adj[u][j];
			if(dad[v] == -1) {
				Q.pb(v);
				dad[v] = u;
			}
		}
	}
}

int calcMatch(int n) {
	vector<int> u(n);
	vector<int> v(n);
	for( int i = 0 ; i < n ; i++ ) {
		u[i] = cost[i][0];
		for( int j = 1 ; j < n ; j++ )
			u[i] = min( u[i] , cost[i][j] );
	}
	for( int j = 0 ; j < n ; j++ ) {
		v[j] = cost[0][j] - u[0];
		for( int i = 1 ; i < n ; i++ )
			v[j] = min( v[j] , cost[i][j] - u[i] );
	}
	vector<int> Lmate(n,-1);
	vector<int> Rmate(n,-1);
	int mated = 0;
	for( int i = 0 ; i < n ; i++ ) {
		for( int j = 0 ; j < n ; j++ ) {
			if(Rmate[j] != -1)
				continue;
			if(cost[i][j] - u[i] - v[j] == 0) {
				Lmate[i] = j;
				Rmate[j] = i;
				mated++;
				break;
			}
		}
	}
	vector<int> dist(n);
	vector<int> dad(n);
	vector<int> seen(n);
	while(mated < n) {
		int s = 0;
		while(Lmate[s] != -1)
			s++;
		fill(dad.begin() , dad.end() , -1);
		fill(seen.begin() , seen.end() , 0);
		for( int k = 0 ; k < n ; k++ )
			dist[k] = cost[s][k] - u[s] - v[k];
		int j = 0;
		while(true) {
			j = -1;
			for( int k = 0 ; k < n ; k++ ) {
				if(seen[k])
					continue;
				if(j == -1 || dist[k] < dist[j])
					j = k;
			}
			seen[j] = 1;
			if(Rmate[j] == -1)
				break;
			const int i = Rmate[j];
			for( int k = 0 ; k < n ; k++ ) {
				if(seen[k])
					continue;
				int new_dist = dist[j] + cost[i][k] - u[i] - v[k];
				if(dist[k] > new_dist) {
					dist[k] = new_dist;
					dad[k] = j;
				}
			}
		}
		for( int k = 0 ; k < n ; k++ ) {
			if(k == j || !seen[k])
				continue;
			const int i = Rmate[k];
			v[k] += dist[k] - dist[j];
			u[i] -= dist[k] - dist[j];
		}
		u[s] += dist[j];
		while(dad[j] >= 0) {
			const int d = dad[j];
			Rmate[j] = Rmate[d];
			Lmate[Rmate[j]] = j;
			j = d;
		}
		Rmate[j] = s;
		Lmate[s] = j;
		mated++;
	}
	int value = 0;
	for( int i = 0 ; i < n ; i++ )
		value += cost[i][Lmate[i]];
	return value;
}

int minCostMatching(int u , int par , int pc , int c) {
	memset(cost,0,sizeof(cost));
	bool minusColor = false;
	for( int i = 1 ; i <= k ; i++ )
		if(i == pc)
			minusColor = true;
		else {
			bool minusPar = false;
			for( int j = 0 ; j < adj[u].size() ; j++ ) {
				int v = adj[u][j];
				if(v == par)
					minusPar = true;
				else
					cost[i-1-minusColor][j-minusPar] = dp[v][c][i];
			}
		}
	return calcMatch(k-minusColor);
}

int solve() {
	for( int s = n-1 ; s >= 0 ; s-- ) {
		int u = Q[s];
		for( int pc = 0 ; pc <= k ; pc++ ) {
			if(u > 1 && pc == 0)
				continue;
			if(u == 1 && pc > 0)
				break;
			best[u][pc] = INT_MAX;
			for( int c = 1 ; c <= k ; c++ ) {
				dp[u][pc][c] = ar[u][c] + p;
				for( int i = 0 ; i < adj[u].size() ; i++ ) {
					int v = adj[u][i];
					if(dad[v] == u)
						dp[u][pc][c] += best[v][c];
				}
				if(adj[u].empty())
					dp[u][pc][c] = ar[u][c];
				else if(adj[u].size() == 1 && u > 1)
					dp[u][pc][c] = ar[u][c];
				else if(adj[u].size() <= k)
					dp[u][pc][c] = min( dp[u][pc][c] , minCostMatching(u,dad[u],pc,c) + ar[u][c] );
				best[u][pc] = min( best[u][pc] , dp[u][pc][c] );
			}
		}
	}
	return best[1][0];
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d%d",&n,&k,&p);
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 1 ; j <= k ; j++ )
				scanf("%d",&ar[i][j]);
		for( int i = 1 , u , v ; i < n ; i++ ) {
			scanf("%d%d",&u,&v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		bfs();
		printf("Case #%d: %d\n",tc,solve());
	}
	return 0;
}
