#include <bits/stdc++.h>
#define pb push_back
#define maxn 100001
#define mod 1000000007
using namespace std;
typedef long long LL;

int T,n,m;
vector<int> p;
vector<LL> ways;
vector<int> mult;
vector<int> adj[maxn];

void reset() {
	p.clear();
	mult.clear();
	ways.clear();
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
}

int dfs(int u , int dad) {
	int cnt = 1;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(v != dad)
			cnt += dfs(v,u);
	}
	if(dad)
		ways.pb((LL)cnt*(n-cnt));
	return cnt;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		for( int i = 1 , x,y ; i < n ; i++ ) {
			scanf("%d%d",&x,&y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		scanf("%d",&m);
		for( int i = 0 , x ; i < m ; i++ ) {
			scanf("%d",&x);
			p.pb(x);
		}
		sort(p.begin(),p.end());
		if(m <= n-1) {
			int diff = n-1-m;
			for( int i = 0 ; i < diff ; i++ )
				mult.pb(1);
			for( int i = 0 ; i < m ; i++ )
				mult.pb(p[i]);
		}
		else {
			for( int i = 0 ; i < n-2 ; i++ )
				mult.pb(p[i]);
			int add = 1;
			for( int i = n-2 ; i < m ; i++ )
				add = (LL) add*p[i] % mod;
			mult.pb(add);
		}
		dfs(1,0);
		sort(ways.begin(),ways.end());
		int ans = 0;
		for( int i = 0 ; i < n-1 ; i++ ) {
			ways[i] %= mod;
			int add = (LL) mult[i]*ways[i] % mod;
			ans = (ans+add) % mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
