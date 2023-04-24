#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 102
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int T,n,m,k,sr,sc,er,ec;
vector<pi> locs;
int bef[maxn][maxn];
int cnt[maxn][maxn];
char str[maxn][maxn];
int dir[4][2] = {{0,-1},{0,+1},{-1,0},{+1,0}};

void reset() {
	locs.clear();
	memset(cnt, 0, sizeof(cnt));
	memset(bef, -1, sizeof(bef));
}

void bfs() {
	queue<pi> Q;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			if( str[i][j] == 'M' )
				sr = i , sc = j;
	bef[sr][sc] = -2;
	Q.push(pi(sr,sc));
	while(!Q.empty()) {
		pi tmp = Q.front();
		Q.pop();
		int r = tmp.fi;
		int c = tmp.se;
		if(str[r][c] == '*') {
			er = r;
			ec = c;
			break;
		}
		for( int i = 0 ; i < 4 ; i++ ) {
			int x = r + dir[i][0];
			int y = c + dir[i][1];
			if( x < 0 || x >= n || y < 0 || y >= m )
				continue;
			if( str[x][y] == 'X' )
				continue;
			cnt[r][c]++;
			if( bef[x][y] != -1 )
				continue;
			bef[x][y] = i;
			Q.push(pi(x,y));
		}
	}
}

void goo(int r, int c) {
	if(str[r][c] == 'M') {
		locs.pb(pi(r,c));
		return;
	}
	int way = bef[r][c];
	goo(r - dir[way][0], c - dir[way][1]);
	locs.pb(pi(r,c));
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&m);
		for( int i = 0 ; i < n ; i++ )
			scanf("%s",str[i]);
		scanf("%d",&k);
		bfs();
		goo(er,ec);
		int res = cnt[sr][sc] != 1;
		for( int i = 1 ; i < (int) locs.size() - 1 ; i++ ) {
			int r = locs[i].fi;
			int c = locs[i].se;
			res += cnt[r][c] != 2;
		}
		if(res == k)
			puts("Impressed");
		else
			puts("Oops!");
	}
	return 0;
}
