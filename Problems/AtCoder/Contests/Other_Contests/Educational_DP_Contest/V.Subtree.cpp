#include <bits/stdc++.h>
#define maxn 100001
#define pb push_back
using namespace std;
typedef long long LL;

int n,m;
int ans[maxn];
int stMult[maxn];
vector<int> adj[maxn];
vector<int> preMult[maxn];
vector<int> sufMult[maxn];
vector<int> children[maxn];

void dfs2(int node, LL upMult) {
	ans[node] = upMult * ( ( stMult[node]-1+m ) % m ) % m;
	int nChild = (int) children[node].size();
	for( int i = 0 ; i < nChild ; i++ ) {
		int to = children[node][i];
		if( i == 0 && i == nChild-1 ) {
			LL newUpMult = (upMult + 1) % m;
			dfs2(to, newUpMult);
		}
		else if( i == 0 ) {
			LL newUpMult = (upMult * sufMult[node][1] % m + 1) % m;
			dfs2(to, newUpMult);
		}
		else if( i == nChild - 1 ) {
			LL newUpMult = (upMult * preMult[node][nChild-2] % m + 1) % m;
			dfs2(to, newUpMult);
		}
		else {
			LL newUpMult = (upMult * preMult[node][i-1]) % m;
			newUpMult = (newUpMult * sufMult[node][i+1]) % m;
			newUpMult = (newUpMult + 1) % m;
			dfs2(to, newUpMult);
		}
	}
}

int dfs(int node, int dad) {
	vector<int> v;
	int allMult = 1;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i];
		if( to != dad ) {
			children[node].pb(to);
			int mult = dfs(to, node);
			v.pb(mult);
			allMult = ( (LL) allMult * mult ) % m;
		}
	}
	if(v.size()) {
		int nChild = v.size();
		preMult[node].pb( v[0] );
		for( int i = 1 ; i < nChild ; i++ )
			preMult[node].pb( ( (LL) preMult[node][i-1] * v[i] ) % m );
		sufMult[node].pb( v[nChild-1] );
		for( int i = nChild-2 ; i >= 0 ; i-- )
			sufMult[node].pb( ( (LL) sufMult[node][nChild-i-2] * v[i] ) % m );
		reverse( sufMult[node].begin() , sufMult[node].end() );
	}
	return stMult[node] = (allMult + 1) % m;
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i < n ; i++ ) {
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,0);
	dfs2(1,1);
	for( int i = 1 ; i <= n ; i++ )
		printf("%d\n",ans[i]);
	return 0;
}
