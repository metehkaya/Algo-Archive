#include <bits/stdc++.h>
#define maxn 1002
using namespace std;

int T,n,k,tc,dfsc;
int ar[maxn];
int outg[maxn];
int mark[maxn];
int forb[maxn][maxn];
bool way[maxn][maxn];

bool dfs(int node) {
	if(node == 2*n+1)
		return true;
	mark[node] = dfsc;
	for( int i = 2*n+1 ; i >= 1 ; i-- )
		if(mark[i] != dfsc && way[node][i]) {
			bool ok = dfs(i);
			if(ok) {
				way[node][i] = false;
				way[i][node] = true;
				return true;
			}
		}
	return false;
}

int main() {
	scanf("%d",&T);
	for( tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		for( int kk = 1 ; kk <= k ; kk++ ) {
			for( int i = 1 ; i <= n ; i++ )
				scanf("%d",&ar[i]);
			for( int i = 1 ; i <= n ; i++ )
				for( int j = i+1 ; j <= n ; j++ )
					forb[ar[j]][ar[i]] = tc;
		}
		for( int i = 0 ; i <= 2*n+1 ; i++ )
			for( int j = 0 ; j <= 2*n+1 ; j++ )
				way[i][j] = false;
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 1 ; j <= n ; j++ )
				if( i != j )
					way[i][j+n] = ( forb[i][j] != tc );
		for( int i = 1 ; i <= n ; i++ )
			way[0][i] = way[i+n][2*n+1] = true;
		bool cond = true;
		do {
			dfsc++;
			cond = dfs(0);
		}while(cond);
		int cnt0 = n;
		for( int i = 1 ; i <= n ; i++ ) {
			outg[i] = 0;
			for( int j = 1 ; j <= n ; j++ )
				if( i != j )
					if( forb[i][j] != tc && !way[i][j+n] ) {
						cnt0--;
						outg[i] = j;
						break;
					}
		}
		printf("%d\n",cnt0);
		for( int i = 1 ; i <= n ; i++ )
			printf("%d ", outg[i]);
		puts("");
	}
	return 0;
}
