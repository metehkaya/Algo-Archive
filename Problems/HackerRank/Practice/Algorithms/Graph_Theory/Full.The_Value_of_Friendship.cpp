#include <bits/stdc++.h>
#define maxn 100003
#define maxm 200003
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int T,n,m,k,cnt;
int st[maxn];
int dad[maxn];
int E[maxm][2];
bool mark[maxn];
vector<int> groups;
vector<int> adj[maxn];

void reset() {
	k = 0;
	groups.clear();
	memset( mark , false , sizeof(mark) );
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
}

void input() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= m ; i++ )
		scanf("%d%d",&E[i][0],&E[i][1]);
}

void mst() {
	for( int i = 1 ; i <= n ; i++ )
		st[i] = 0 , dad[i] = i;
	for( int i = 1 ; i <= m ; i++ ) {
		int x = E[i][0] , y = E[i][1];
		while(x != dad[x])
			x = dad[x];
		while(y != dad[y])
			y = dad[y];
		if(x == y) {
			k++;
			continue;
		}
		if(st[x] < st[y])
			dad[x] = y;
		else if(st[x] > st[y])
			dad[y] = x;
		else {
			dad[y] = x;
			st[x]++;
		}
		adj[E[i][0]].pb(E[i][1]);
		adj[E[i][1]].pb(E[i][0]);
	}
}

void dfs_visit( int node ) {
	cnt++;
	mark[node] = true;
	for( int i = 0 ; i < adj[node].size() ; i++ )
		if(!mark[ adj[node][i]])
			dfs_visit(adj[node][i]);
}

void dfs() {
	for( int i = 1 ; i <= n ; i++ )
		if(!mark[i]) {
			cnt = 0;
			dfs_visit(i);
			groups.pb(cnt);
		}
	sort(groups.begin(),groups.end());
}

void solve() {
	LL ans = 0 , sum = 0;
	for( int i = groups.size() - 1 ; i >= 0 ; i-- ) {
		LL e = groups[i]-1;
		LL add = e*(e+1)*(2*e+1)/6 + e*(e+1)/2;
		ans += sum*e + add;
		sum += e*(e+1);
	}
	ans += sum*k;
	printf("%lld\n",ans);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		mst();
		dfs();
		solve();
	}
	return 0;
}
