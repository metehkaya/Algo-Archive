#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int T,n,m;
int cntr[20];
int cntc[20];
int G[42][42];
bool mark[42];
int mat[20][20];
const int TIMES = 1000;

int dfs(int u , int curr) {
	mark[u] = true;
	if(u == n+m+1) {
		return curr;
	}
	vector<int> v;
	for( int i = 0 ; i < n+m+2 ; i++ )
		if(G[u][i] && !mark[i])
			v.pb(i);
	int sz = v.size();
	random_shuffle(v.begin(), v.end());
	for( int s = 0 ; s < sz ; s++ ) {
		int i = v[s];
		int val = dfs(i,min(curr,G[u][i]));
		if(val > 0) {
			G[u][i] -= val;
			G[i][u] += val;
			return val;
		}
	}
	return 0;
}

bool solve(int tc) {
	memset(G,0,sizeof(G));
	for( int i = 0 ; i < n ; i++ )
		G[0][i+1] = cntr[i];
	for( int i = 0 ; i < m ; i++ )
		G[n+1+i][n+m+1] = cntc[i];
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			G[i+1][n+1+j] = 1;
	memset(mark,false,sizeof(mark));
	while(dfs(0,INT_MAX)) {
		memset(mark,false,sizeof(mark));
	}
	bool ok = true;
	for( int i = 0 ; i < n ; i++ )
		if(G[0][i+1])
			ok = false;
	for( int i = 0 ; i < m ; i++ )
		if(G[n+1+i][n+m+1])
			ok = false;
	if(!ok)
		return false;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			mat[i][j] = !G[i+1][n+1+j];
	bool sqfree = true;
	for( int i = 0 ; i < n && sqfree ; i++ )
		for( int j = 0 ; j < m-1 && sqfree ; j++ )
			if(mat[i][j] == 1 && mat[i][j+1] == 0) {
				int a = (n-i)/2;
				int b = j+1;
				int c = m-1-j;
				int maxlen = min( min(a,b) , c );
				for( int len = 1 ; len <= maxlen ; len++ ) {
					bool ok = false;
					for( int k = 0 ; k < len ; k++ )
						if(mat[i+k][j-k] == 0 || mat[i+k][j+1+k] == 1 || mat[i+len+k][j-(len-1)+k] == 1 || mat[i+len+k][j+len-k] == 0) {
							ok = true;
							break;
						}
					if(!ok) {
						sqfree = false;
						break;
					}
				}
			}
	if(!sqfree)
		return false;
	printf("Case #%d: POSSIBLE\n",tc);
	for( int i = 0 ; i < n ; i++ , puts("") )
		for( int j = 0 ; j < m ; j++ )
			printf("%c",(mat[i][j] == 1) ? '/' : '\\');
	return true;
}

int main() {
	srand(time(NULL));
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&m);
		int diff = 0;
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&cntr[i]);
			diff += cntr[i];
		}
		for( int i = 0 ; i < m ; i++ ) {
			scanf("%d",&cntc[i]);
			diff -= cntc[i];
		}
		bool var = false;
		if(diff == 0)
			for( int ttt = 0 ; ttt < TIMES && !var ; ttt++ )
				var = solve(tc);
		if(!var)
			printf("Case #%d: IMPOSSIBLE\n",tc);
	}
	return 0;
}
