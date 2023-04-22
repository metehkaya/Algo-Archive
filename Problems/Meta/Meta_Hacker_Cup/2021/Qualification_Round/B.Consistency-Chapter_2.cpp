#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int T,n,m;
string s;
int d[26];
bool isvowel[26];
vector<int> adj[26];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void init() {
	isvowel['A'-'A'] = true;
	isvowel['E'-'A'] = true;
	isvowel['I'-'A'] = true;
	isvowel['O'-'A'] = true;
	isvowel['U'-'A'] = true;
}

void reset() {
	for( int i = 0 ; i < 26 ; i++ )
		adj[i].clear();
}

void graph() {
	string e;
	cin >> e;
	int u = e[0]-'A';
	int v = e[1]-'A';
	adj[v].pb(u);
}

void bfs(int root) {
	queue<int> Q;
	memset(d,-1,sizeof(d));
	Q.push(root);
	d[root] = 0;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			if(d[v] == -1) {
				Q.push(v);
				d[v] = d[u]+1;
			}
		}
	}
}

int solve() {
	int ans = -1;
	for( int c = 0 ; c < 26 ; c++ ) {
		bfs(c);
		int sum = 0;
		for( int i = 0 ; i < n ; i++ ) {
			int k = s[i]-'A';
			if(d[k] == -1) {
				sum = -1;
				break;
			}
			sum += d[k];
		}
		if(sum != -1)
			if(ans == -1 || sum < ans)
				ans = sum;
	}
	return ans;
}

int main() {
	io();
	init();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		cin >> s >> m;
		n = s.length();
		for( int i = 0 ; i < m ; i++ )
			graph();
		int ans = solve();
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
