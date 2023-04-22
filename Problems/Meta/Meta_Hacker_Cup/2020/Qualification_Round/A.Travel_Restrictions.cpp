#include <bits/stdc++.h>
#define maxn 50
#define pb push_back
using namespace std;

int T,n;
bool mark[maxn];
string in,out,ans;
vector<int> adj[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	for( int i = 0 ; i < n ; i++ )
		adj[i].clear();
}

void dfs(int u) {
	ans[u] = 'Y';
	mark[u] = true;
	for( int i = 0 ; i < adj[u].size() ; i++ ) {
		int v = adj[u][i];
		if(mark[v])
			continue;
		dfs(v);
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		cin >> in >> out;
		printf("Case #%d: \n",tc);
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < n ; j++ )
				if(abs(i-j) == 1 && out[i] == 'Y' && in[j] == 'Y')
					adj[i].pb(j);
		for( int i = 0 ; i < n ; i++ ) {
			ans = "";
			for( int j = 0 ; j < n ; j++ )
				ans.pb('N');
			memset(mark,false,sizeof(mark));
			dfs(i);
			cout << ans << endl;
		}
	}
	return 0;
}
