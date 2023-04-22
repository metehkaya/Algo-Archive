#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

int T,n,m;
int laser[256];
int sx,sy,ex,ey;
int dist[maxn][maxn][4];
bool forb[maxn][maxn][4];
int dir[4][2] = {{-1,0},{0,+1},{+1,0},{0,-1}};
string s[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	memset(dist,-1,sizeof(dist));
	memset(forb,false,sizeof(forb));
}

void init() {
	laser['^'] = 1;
	laser['>'] = 2;
	laser['v'] = 3;
	laser['<'] = 4;
}

int bfs() {
	queue<pii> Q;
	dist[sx][sy][0] = 0;
	Q.push(pii(pi(sx,sy),0));
	while(!Q.empty()) {
		pii temp = Q.front();
		Q.pop();
		int x = temp.fi.fi;
		int y = temp.fi.se;
		int k = temp.se;
		if(x == ex && y == ey)
			return dist[x][y][k];
		for( int i = 0 ; i < 4 ; i++ ) {
			int r = x+dir[i][0];
			int c = y+dir[i][1];
			int st = (k+1) % 4;
			if(r < 0 || r == n || c < 0 || c == m)
				continue;
			if(s[r][c] == '#' || laser[s[r][c]])
				continue;
			if(forb[r][c][st] || dist[r][c][st] != -1)
				continue;
			Q.push(pii(pi(r,c),st));
			dist[r][c][st] = dist[x][y][k]+1;
		}
	}
	return -1;
}

int main() {
	io();
	init();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&m);
		for( int i = 0 ; i < n ; i++ )
			cin >> s[i];
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ ) {
				if(s[i][j] == 'S')
					sx = i , sy = j;
				else if(s[i][j] == 'G')
					ex = i , ey = j;
				else if(laser[s[i][j]]) {
					int laserDir = laser[s[i][j]] - 1;
					for( int k = 0 ; k < 4 ; k++ ) {
						int ldir = (laserDir+k) % 4;
						int x = i + dir[ldir][0];
						int y = j + dir[ldir][1];
						while(x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '#' && !laser[s[x][y]]) {
							forb[x][y][k] = true;
							x += dir[ldir][0];
							y += dir[ldir][1];
						}
					}
				}
			}
		int ans = bfs();
		if(ans == -1)
			printf("Case #%d: impossible\n",tc);
		else
			printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
