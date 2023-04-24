#include <bits/stdc++.h>
#define maxn 500003
#define pb push_back
using namespace std;
typedef long long LL;

int n,m,res;
int cnt[101];
vector<int>adj[101];

int dfs(int node, int dad) {
	cnt[node]++;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i];
		if(to != dad)
			cnt[node] += dfs(to, node);
	}
	if(cnt[node] % 2 == 0)
		res++;
	return cnt[node];
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ,x,y ; i < m ; i++ ) {
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,0);
	printf("%d\n",--res);
	return 0;
}
