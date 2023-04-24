#include <bits/stdc++.h>
using namespace std;

const int K = 26;

int T,n,m;
int mark[K];
bool var[K];
bool G[K][K];
char str[35][35];
bool isPossible;
string ans;

void reset() {
	ans = "";
	isPossible = true;
	memset(G, 0, sizeof(G));
	memset(var, 0, sizeof(var));
	memset(mark, 0, sizeof(mark));
}

void dfs(int u) {
	mark[u] = 1;
	char c = 'A' + u;
	for( int i = 0 ; i < K ; i++ )
		if( G[u][i] ) {
			if(mark[i] == 1) {
				isPossible = false;
				return;
			}
			else if(mark[i] == 0)
				dfs(i);
		}
	mark[u] = 2;
	ans.push_back(c);
}

int main() {
	cin >> T;
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&m);
		for( int i = 0 ; i < n ; i++ )
			scanf("%s",str[i]);
		for( int i = 0 ; i < m ; i++ )
			var[ str[0][i] - 'A' ] = true;
		for( int i = 1 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ ) {
				int x = str[i][j] - 'A';
				int y = str[i-1][j] - 'A';
				var[x] = true;
				if(x != y)
					G[x][y] = true;
			}
		for( int i = 0 ; isPossible && i < K ; i++ )
			if( var[i] && !mark[i] )
				dfs(i);
		printf("Case #%d: ",tc);
		reverse(ans.begin(), ans.end());
		if(isPossible)
			printf("%s\n", ans.c_str());
		else
			puts("-1");
	}
	return 0;	
}
