#include <bits/stdc++.h>
#define maxm 501
#define maxM 25001
#define maxn 200001
#define pb push_back
using namespace std;

int n,m,q,t;
int dad[maxn];
int group[maxn];
int chain[maxm];
int res[maxm][maxm];
vector<int> dts[maxM];
vector<int> fts[maxM];
vector<int> adj[maxn];

void dfs2(int u) {
	t++;
	int deg = adj[u].size();
	dts[group[u]].pb(t);
	for( int i = 0 ; i < deg ; i++ )
		dfs2(adj[u][i]);
	fts[group[u]].pb(t);
}

void dfs1(int u) {
	int deg = adj[u].size();
	for( int i = 1 ; i <= m ; i++ )
		res[i][group[u]] += chain[i];
	chain[group[u]]++;
	for( int i = 0 ; i < deg ; i++ )
		dfs1(adj[u][i]);
	chain[group[u]]--;
}

int main() {
	scanf("%d%d%d",&n,&m,&q);
	scanf("%d",&group[1]);
	for( int i = 2 ; i <= n ; i++ ) {
		scanf("%d%d",&dad[i],&group[i]);
		adj[dad[i]].pb(i);
	}
	if(m < maxm) {
		dfs1(1);
		for( int tc = 0 , x,y ; tc < q ; tc++ ) {
			scanf("%d%d",&x,&y);
			printf("%d\n",res[x][y]);
			fflush(stdout);
		}
	}
	else {
		dfs2(1);
		for( int tc = 0 , x,y ; tc < q ; tc++ ) {
			scanf("%d%d",&x,&y);
			int add = 0 , ans = 0;
			int i = 0 , j = 0 , k = 0;
			int szx = dts[x].size();
			int szy = dts[y].size();
			while(i < szx || j < szx || k < szy) {
				int a = (i < szx) ? dts[x][i] : INT_MAX;
				int b = (j < szx) ? fts[x][j] : INT_MAX;
				int c = (k < szy) ? dts[y][k] : INT_MAX;
				int mn = min(min(a,b),c);
				if(c == mn)
					ans += add , k++;
				else if(a == mn)
					add++ , i++;
				else if(b == mn)
					add-- , j++;
			}
			printf("%d\n",ans);
			fflush(stdout);
		}
	}
	return 0;
}
