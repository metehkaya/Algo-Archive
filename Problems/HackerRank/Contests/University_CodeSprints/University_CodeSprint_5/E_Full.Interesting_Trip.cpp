#include <bits/stdc++.h>
#define maxn 200003
#define pb push_back
using namespace std;

time_t start;
int n,m,s,f,t;
int st[maxn];
char str[maxn];
bool var[maxn];
bool mark[maxn];
string best,curr;
vector<int> G[maxn];
vector<int> adj[maxn];
vector<int> adj2[maxn];

bool comp(int x , int y) {
	return str[x] < str[y];
}

void dfs(int node) {
	mark[node] = true;
	if(node == f) {
		st[++t] = node;
		return;
	}
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i];
		if(!mark[to])
			dfs(to);
	}
	st[++t] = node;
}

bool solve(int node) {
	if(difftime(time(0),start) > 1.996)
		return true;
	curr.pb(str[node]);
	if(node == f) {
		if(best == "" || curr.compare(best) < 0)
			best = curr;
		curr.pop_back();
		return false;
	}
	for( int i = 0 ; i < (int) G[node].size() ; i++ )
		if(solve(G[node][i]))
			return true;
	curr.pop_back();
	return false;
}

int main() {
	start = time(0);
	scanf("%d%d%s",&n,&m,str+1);
	for( int i = 0 , x,y ; i < m ; i++ ) {
		scanf("%d%d",&x,&y);
		adj2[x].pb(y);
	}
	scanf("%d%d",&s,&f);
	for( int i = 1 ; i <= n ; i++ )
		sort(adj2[i].begin(),adj2[i].end(),comp);
	for( int i = 1 ; i <= n ; i++ ) {
		int prev = 0;
		for( int j = 0 ; j < adj2[i].size() ; j++ ) {
			int to = adj2[i][j];
			if(to == prev)
				continue;
			adj[i].pb(to);
			prev = to;
		}
	}
	dfs(s);
	bool foundF = false;
	for( int tt = 1 ; tt <= t ; tt++ ) {
		int node = st[tt];
		if(node == f) {
			foundF = true;
			var[f] = true;
		}
		else if(foundF) {
			for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
				int to = adj[node][i];
				if(!var[to])
					continue;
				if(G[node].size() && str[to] != str[G[node][0]])
					break;
				var[node] = true;
				G[node].pb(to);
			}
		}
	}
	solve(s);
	if(best == "")
		puts("No way");
	else
		cout << best << endl;
    return 0;
}
