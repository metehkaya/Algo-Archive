#include <bits/stdc++.h>
#define maxn 100000
#define pb push_back
using namespace std;
typedef long long LL;

LL ans;
int n,m;
bool mark[maxn];
vector<int>v;
vector<int>adj[maxn];

int dfs(int node) {
	int cnt = 1;
	mark[node] = true;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i];
		if(!mark[to])
			cnt += dfs(to);
	}
	return cnt;
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x , y ; i < m ; i++ ) {
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for( int i = 0 ; i < n ; i++ )
		if(!mark[i])
			v.pb(dfs(i));
	for( int i = 0 , sum = 0 ; i < (int) v.size() ; i++ ) {
		int val = v[i];
		ans += (LL) val * sum;
		sum += val;
	}
	printf("%lld\n",ans);
	return 0;
}
