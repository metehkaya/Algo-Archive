#include <bits/stdc++.h>
#define fi first
#define se second
#define maxk 17
#define maxr 450
#define maxc 169
#define maxn 100001
#define maxp 1900002
#define maxs1 1001
#define maxs2 1000001
#define mod 1000000007
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;

int T,n,m,t,p;
int dt[maxn];
int ft[maxn];
int ar[maxn];
int ans[maxn];
bool var[maxn];
int curr[maxs2];
int arr[2*maxn];
int invfac[maxp];
int bigPrime[maxs2];
int par[maxn][maxk];
int indexPrime[maxs2];
int primeTotal[maxn][maxc];
pii queries[maxn];
vector<int> adj[maxn];
vector<pi> prscnts[maxs2];
vector<int> primeDivs[maxs2];

int calcPow(int x, int y) {
	if(y == 0)
		return 1;
	int res = calcPow(x, y/2);
	res = (LL) res * res % mod;
	if(y & 1)
		res = (LL) res * x % mod;
	return res;
}

int calcRev(int x) {
	return calcPow(x, mod-2);
}

void precalc() {
	for( int i = 2 ; i < maxs2 ; i++ )
		if( primeDivs[i].empty() ) {
			indexPrime[i] = ++p;
			for( int j = i ; j < maxs2 ; j += i )
				primeDivs[j].pb(i);
		}
	for( int i = 2 ; i < maxs2 ; i++ ) {
		int tmp = i;
		for( int j = 0 ; j < (int) primeDivs[i].size() ; j++ ) {
			int cnt = 0;
			int val = primeDivs[i][j];
			while(tmp % val == 0) {
				cnt++;
				tmp /= val;
			}
			if(val < maxs1)
				prscnts[i].pb( pi( val , cnt ) );
			else
				bigPrime[i] = val;
		}
	}
	for( int i = 1 ; i < maxp ; i++ )
		invfac[i] = calcRev(i);
}

void dfs(int node, int dad) {
	dt[node] = ++t;
	arr[t] = node;
	for( int i = 1 ; i < maxc ; i++ )
		primeTotal[node][i] = primeTotal[dad][i];
	for( int i = 0 ; i < (int) prscnts[ar[node]].size() ; i++ ) {
		int pr = prscnts[ar[node]][i].fi;
		int cnt = prscnts[ar[node]][i].se;
		int index = indexPrime[pr];
		primeTotal[node][index] += cnt;
	}
	par[node][0] = dad;
	for( int i = 1 ; i < maxk ; i++ )
		par[node][i] = par[par[node][i-1]][i-1];
	for( int i = 0 ; i < (int) adj[node].size() ; i++ )
		if( adj[node][i] != dad )
			dfs( adj[node][i] , node );
	ft[node] = ++t;
	arr[t] = node;
}

int findLCA(int u, int v) {
	if(dt[u] <= dt[v] && ft[v] <= ft[u])
		return u;
	int tmp, res=1;
	for( int i = maxk-1 ; i >= 0 ; i-- ) {
		tmp = par[u][i];
		if(!tmp)
			continue;
		if(dt[tmp] <= dt[v] && ft[v] <= ft[tmp])
			res = tmp;
		else
			u = tmp;
	}
	return res;
}

void reset() {
	t = 0;
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
	memset(var, 0, sizeof(var));
	memset(curr, 0, sizeof(curr));
	memset(primeTotal, 0, sizeof(primeTotal));
}

bool comp(pii a , pii b) {
	if( a.fi.fi / maxr != b.fi.fi / maxr )
		return a.fi.fi < b.fi.fi;
	return a.fi.se < b.fi.se;
}

int removeNumber(int val, int res) {
	if(bigPrime[val]) {
		int pr = bigPrime[val];
		res = ( (LL) res * invfac[curr[pr]+1] ) % mod;
		res = ( (LL) res * curr[pr] ) % mod;
		curr[pr]--;
	}
	return res;
}

int addNumber(int val, int res, bool change = true) {
	if(bigPrime[val]) {
		int pr = bigPrime[val];
		res = ( (LL) res * invfac[curr[pr]+1] ) % mod;
		res = ( (LL) res * (curr[pr]+2) ) % mod;
		if(change)
			curr[pr]++;
	}
	return res;
}

int addNode(int node, int res) {
	var[node] = true;
	return addNumber(ar[node], res);
}

int removeNode(int node, int res) {
	var[node] = false;
	return removeNumber(ar[node], res);
}

int dealNode(int node, int res) {
	if(var[node])
		return removeNode(node, res);
	return addNode(node, res);
}

int dealSmallNumbers(int u, int v, int lca, int res) {
	int cnt[maxc];
	memset(cnt, 0, sizeof(cnt));
	for( int i = 1 ; i < maxc ; i++ )
		cnt[i] += primeTotal[u][i];
	for( int i = 1 ; i < maxc ; i++ )
		cnt[i] += primeTotal[v][i];
	for( int i = 1 ; i < maxc ; i++ )
		cnt[i] -= primeTotal[lca][i];
	if(lca != 1) {
		int lcap = par[lca][0];
		for( int i = 1 ; i < maxc ; i++ )
			cnt[i] -= primeTotal[lcap][i];
	}
	for( int i = 1 ; i < maxc ; i++ )
		res = ( (LL) res * (cnt[i]+1) ) % mod;
	return res;
}

int main() {
	precalc();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		for( int i = 1 ; i < n ; i++ ) {
			int x,y;
			scanf("%d%d",&x,&y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		dfs(1,0);
		scanf("%d",&m);
		for( int i = 1 ; i <= m ; i++ ) {
			int u,v;
			scanf("%d%d",&u,&v);
			if(dt[u] > dt[v])
				swap(u,v);
			int lca = findLCA(u,v);
			if(u == lca)
				queries[i] = pii( pi( dt[u] , dt[v] ) , pi( -1 , i ) );
			else
				queries[i] = pii( pi( ft[u] , dt[v] ) , pi( lca , i ) );
		}
		sort( queries+1 , queries+m+1 , comp );
		for( int i=1 , l=1 , r=0 , res=1 ; i <= m ; i++ ) {
			int left = queries[i].fi.fi;
			int right = queries[i].fi.se;
			int lca = queries[i].se.fi;
			int index = queries[i].se.se;
			int u = arr[left];
			int v = arr[right];
			while(r < right)
				res = dealNode(arr[++r], res);
			while(l > left)
				res = dealNode(arr[--l], res);
			while(r > right)
				res = dealNode(arr[r--], res);
			while(l < left)
				res = dealNode(arr[l++], res);
			if(lca == -1)
				ans[index] = res, lca = u;
			else
				ans[index] = addNumber(ar[lca], res, false);
			ans[index] = dealSmallNumbers(u,v,lca,ans[index]);
		}
		for( int i = 1 ; i <= m ; i++ )
			printf("%d\n",ans[i]);
	}
	return 0;
}
