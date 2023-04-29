#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pi;

int T,type,sr,sc;
int p[2][3];
int dist[5][8][8][8][8];
int dirT[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int dirB[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
int dirK[8][2] = {{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1}};
queue<pi> Q;

bool checkInside(int r , int c) {
	if(r < 0 || r >= 8 || c < 0 || c >= 8)
		return false;
	return true;
}

void addQ(int r , int c , int& d) {
	if(dist[type][sr][sc][r][c] != -1)
		return;
	dist[type][sr][sc][r][c] = d+1;
	Q.push(pi(r,c));
}

void dealKnight(int x , int y , int& d) {
	for( int i = 0 ; i < 8 ; i++ ) {
		int r = x + dirK[i][0];
		int c = y + dirK[i][1];
		if(checkInside(r,c))
			addQ(r,c,d);
	}
}

void dealBishop(int x , int y , int& d) {
	for( int i = 0 ; i < 4 ; i++ ) {
		int r = x + dirB[i][0];
		int c = y + dirB[i][1];
		while(checkInside(r,c)) {
			addQ(r,c,d);
			r += dirB[i][0];
			c += dirB[i][1];
		}
	}
}

void dealTower(int x , int y , int& d) {
	for( int i = 0 ; i < 4 ; i++ ) {
		int r = x + dirT[i][0];
		int c = y + dirT[i][1];
		while(checkInside(r,c)) {
			addQ(r,c,d);
			r += dirT[i][0];
			c += dirT[i][1];
		}
	}
}

void dealQueen(int x , int y , int& d) {
	dealTower(x,y,d);
	dealBishop(x,y,d);
}

void dealKing(int x , int y , int& d) {
	for( int i = 0 ; i < 4 ; i++ ) {
		int r = x + dirT[i][0];
		int c = y + dirT[i][1];
		if(checkInside(r,c))
			addQ(r,c,d);
	}
	for( int i = 0 ; i < 4 ; i++ ) {
		int r = x + dirB[i][0];
		int c = y + dirB[i][1];
		if(checkInside(r,c))
			addQ(r,c,d);
	}
}

void dealPlayer(int r , int c , int& d) {
	if(type == 0)
		dealKing(r,c,d);
	else if(type == 1)
		dealKnight(r,c,d);
	else if(type == 2)
		dealQueen(r,c,d);
	else if(type == 3)
		dealTower(r,c,d);
	else if(type == 4)
		dealBishop(r,c,d);
}

void clearQ() {
	while(!Q.empty())
		Q.pop();
}

void bfs() {
	clearQ();
	Q.push(pi(sr,sc));
	dist[type][sr][sc][sr][sc] = 0;
	while(!Q.empty()) {
		pi pl = Q.front();
		Q.pop();
		int r = pl.fi , c = pl.se;
		int d = dist[type][sr][sc][r][c];
		dealPlayer(r,c,d);
	}
}

int main() {
	memset(dist,-1,sizeof(dist));
	for( type = 0 ; type < 5 ; type++ )
		for( sr = 0 ; sr < 8 ; sr++ )
			for( sc = 0 ; sc < 8 ; sc++ )
				bfs();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		for( int i = 0 ; i < 2 ; i++ )
			for( int j = 0 ; j < 3 ; j++ )
				scanf("%d",&p[i][j]);
		int ans = -1;
		for( int i = 0 ; i < 8 ; i++ )
			for( int j = 0 ; j < 8 ; j++ )
				if(dist[p[0][0]][p[0][1]][p[0][2]][i][j] != -1 && dist[p[1][0]][p[1][1]][p[1][2]][i][j] != -1) {
					int d = dist[p[0][0]][p[0][1]][p[0][2]][i][j] + dist[p[1][0]][p[1][1]][p[1][2]][i][j];
					if(ans == -1 || d < ans)
						ans = d;
				}
		if(ans == -1)
			puts("INF");
		else
			printf("%d\n",ans);
	}
	return 0;
}
