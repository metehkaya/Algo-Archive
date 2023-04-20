#include <bits/stdc++.h>
#define maxn 1000
using namespace std;

int n,m,ans;
string s[maxn];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int x , int y) {
	s[x][y] = '#';
	for( int i = 0 ; i < 4 ; i++ ) {
		int a = x + dir[i][0];
		int b = y + dir[i][1];
		if(a < 0 || a >= n || b < 0 || b >= m || s[a][b] == '#')
			continue;
		dfs(a,b);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i++ )
		cin >> s[i];
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			if(s[i][j] == '.') {
				ans++;
				dfs(i,j);
			}
	printf("%d\n",ans);
	return 0;
}