#include <bits/stdc++.h>
#include "friend.h"
#define maxn 1003
#define pb push_back
using namespace std;

int n;
int cntg[2];
int tc[maxn];
int col[maxn];
int bef[maxn];
int dp[maxn][2];
int G[maxn][maxn];
bool mat[maxn][maxn];
vector<int> scores;
vector<int> adj[maxn];

int solve1() {
	int res = 0;
	int N = (1<<n);
	for( int bmask = 1 ; bmask < N ; bmask++ ) {
		int sum = 0;
		vector<int> vec;
		for( int i = 0 ; i < n ; i++ )
			if(bmask&(1<<i)) {
				vec.pb(i);
				sum += scores[i];
			}
		int sz = vec.size();
		bool ok = true;
		for( int i = 0 ; i < sz ; i++ )
			for( int j = 0 ; j < sz ; j++ ) {
				int u = vec[i];
				int v = vec[j];
				if(mat[u][v])
					ok = false;
			}
		if(ok)
			res = max(res,sum);
	}
	return res;
}

int solve2() {
	int sum = 0;
	for( int i = 0 ; i < n ; i++ )
		sum += scores[i];
	return sum;
}

int solve3() {
	int mx = 0;
	for( int i = 0 ; i < n ; i++ )
		mx = max(mx,scores[i]);
	return mx;
}

int f(int u , int st , int dad) {
	if(dp[u][st] != -1)
		return dp[u][st];
	dp[u][st] = 0;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v != dad)
			dp[u][st] += f(v,1,u);
	}
	if(st) {
		int sum = scores[u];
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			if(v != dad)
				sum += f(v,0,u);
		}
		dp[u][st] = max(dp[u][st],sum);
	}
	return dp[u][st];
}

int solve4() {
	memset(dp,-1,sizeof(dp));
	return f(0,1,-1);
}

void dfs(int u) {
	cntg[col[u]]++;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(col[v] == -1) {
			col[v] = !col[u];
			dfs(v);
		}
	}
}

int bfs(int bfscnt) {
	queue<int> Q;
	Q.push(0);
	tc[0] = bfscnt;
	while(!Q.empty()) {
		int u = Q.front();
		for( int v = 0 ; v <= n+1 ; v++ )
			if(tc[v] != bfscnt) {
				Q.push(v);
				bef[v] = u;
				tc[v] = bfscnt;
			}
	}
}

// TLE
int solve5() {
	memset(col,-1,sizeof(col));
	for( int i = 0 ; i < n ; i++ )
		if(col[i] == -1) {
			col[i] = 0;
			dfs(i);
		}
	for( int i = 0 ; i < n ; i++ ) {
		if(col[i] == 0)
			G[0][i+1] = 1;
		else
			G[i+1][n+1] = 1;
		for( int j = i+1 ; j < n ; j++ )
			if(mat[i][j]) {
				if(col[i] == 0)
					G[i+1][j+1] = 1;
				else
					G[j+1][i+1] = 1;
			}
	}
	int cntbfs = 0;
	int res = n , p;
	while(p = bfs(++cntbfs)) {
		res -= p;
		int u = n+1;
		while(u != 0) {
			int v = bef[u];
			G[v][u] -= p;
			G[u][v] += p;
			u = v;
		}
	}
	return res;
}

int findSample(int N, int score[], int host[], int type[]) {
	n = N;
	int ans = 0;
	int bmask = 0;
	scores.pb(score[0]);
	for( int i = 1 ; i < N ; i++ ) {
		scores.pb(score[i]);
		int u = host[i];
		bmask |= (1<<type[i]);
		if(type[i] == 0) {
			adj[i].pb(u);
			adj[u].pb(i);
			mat[u][i] = mat[i][u] = true;
		}
		else if(type[i] == 1) {
			int deg = adj[u].size();
			for( int j = 0 ; j < deg ; j++ ) {
				int to = adj[u][j];
				adj[i].pb(to);
				adj[to].pb(i);
				mat[to][i] = mat[i][to] = true;
			}
		}
		else {
			int deg = adj[u].size();
			for( int j = 0 ; j < deg ; j++ ) {
				int to = adj[u][j];
				adj[i].pb(to);
				adj[to].pb(i);
				mat[to][i] = mat[i][to] = true;
			}
			adj[i].pb(u);
			adj[u].pb(i);
			mat[u][i] = mat[i][u] = true;
		}
	}
	if(n <= 10)
		ans = solve1();
	else if(bmask == 2)
		ans = solve2();
	else if(bmask == 4)
		ans = solve3();
	else if(bmask == 1)
		ans = solve4();
	else if(bmask == 3)
		ans = solve5();
	return ans;
}
