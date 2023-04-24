#include <bits/stdc++.h>
#define maxn 300002
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

LL mn,mx;
int n,m,a,b,ans;
bool mark[maxn];
vector<int> v;
vector<int> adj[maxn];

void dfs(int node) {
	v.pb( node );
	mark[node] = true;
	mn = min(mn,(LL)a*(LL)adj[node].size());
	mx = max(mx,(LL)b*(LL)adj[node].size());
	for( int i = 0 ; i < (int) adj[node].size() ; i++ )
		if(!mark[adj[node][i]])
			dfs(adj[node][i]);
}

int main() {
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for( int i = 0 , x,y ; i < m ; i++ ) {
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for( int i = 1 ; i <= n ; i++ )
		if(!mark[i]) {
			v.clear();
			mx = 0;
			mn = (1LL<<60);
			dfs(i);
			for( int j = 0 ; j < v.size() ; j++ ) {
				int sz = adj[ v[j] ].size();
				if(mn < sz && sz < mx)
					ans++;
			}
		}
	printf("%d\n",ans);
	return 0;
}
