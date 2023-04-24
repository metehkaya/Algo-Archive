#include <bits/stdc++.h>
#define maxn 100001
#define mod 1000000007
#define pb push_back
using namespace std;
typedef long long LL;

LL ans;
int T,n;
int v[maxn];
LL fact[maxn];
set<int> adj[maxn];
vector<int> G[maxn];

void reset() {
	for( int i = 0 ; i < n ; i++ ) {
		G[i].clear();
		adj[i].clear();
	}
}

LL invf(LL x , int y) {
	if(y == 0)
		return 1;
	LL t = invf(x,y/2);
	t = (t*t) % mod;
	if(y & 1)
		t = (t*x) % mod;
	return t;
}

LL getComb(int x , int y) {
	LL a = fact[x];
	LL b = (fact[y] * fact[x-y]) % mod;
	b = invf(b,mod-2);
	LL c = (a*b) % mod;
	return c;
}

int dfs(int u) {
	int sum = 0;
	int deg = G[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = G[u][i];
		int sz = dfs(v);
		sum += sz;
		ans = (ans * getComb(sum,sz)) % mod;
	}
	return ++sum;
}

int main() {
	fact[0] = 1;
	for( int i = 1 ; i < maxn ; i++ )
		fact[i] = (fact[i-1]*i) % mod;
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&v[i]);
		stack<int> st;
		st.push(0);
		int sz = 1;
		bool imp = false;
		for( int i = 1 ; i < n && !imp ; i++ ) {
			if(v[i] > v[i-1]+1) {
				imp = true;
				break;
			}
			else if(v[i] == v[i-1]+1)
				adj[i-1].insert(i);
			else {
				int times = v[i-1]-v[i]+1;
				if(times > sz) {
					imp = true;
					break;
				}
				int x,y;
				while(times--) {
					int idx = st.top();
					st.pop();
					sz--;
					if(times == 0)
						x = idx;
				}
				if(!st.empty()) {
					int y = st.top();
					adj[y].erase(x);
					adj[y].insert(i);
					adj[i].insert(x);
				}
				else
					adj[i].insert(x);
			}
			sz++;
			st.push(i);
		}
		if(imp)
			ans = 0;
		else {
			for( int i = 0 ; i < n ; i++ ) {
				set<int>::iterator it = adj[i].begin();
				while(it != adj[i].end()) {
					int idx = (*it);
					G[i].pb(idx);
					it++;
				}
			}
			ans = 1;
			int root;
			while(!st.empty()) {
				root = st.top();
				st.pop();
			}
			dfs(root);
		}
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
