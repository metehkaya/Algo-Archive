#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pi;

int n,ax,ay,bx,by;
int dist[200][200];
int best[200][200];
bool mark[200][200];
int yon[6][2] = {{-2,-1},{-2,+1},{0,+2},{+2,+1},{+2,-1},{0,-2}};
string commands[6] = {"UL","UR","R","LR","LL","L"};

void goo(int x , int y) {
	if(x == ax && y == ay)
		return;
	int dir = best[x][y];
	goo(x-yon[dir][0],y-yon[dir][1]);
	cout << commands[dir] << " ";
}

void bfs() {
	queue<pi> q;
	bool found = false;
	q.push(pi(ax,ay));
	mark[ax][ay] = true;
	while(!q.empty()) {
		pi tmp = q.front();
		q.pop();
		int x = tmp.fi;
		int y = tmp.se;
		if(x == bx && y == by) {
			found = true;
			printf("%d\n",dist[bx][by]);
			goo(bx,by);
			break;
		}
		for( int i = 0 ; i < 6 ; i++ ) {
			int cx = x + yon[i][0];
			int cy = y + yon[i][1];
			if(cx < 0 || cx >= n || cy < 0 || cy >= n)
				continue;
			if(mark[cx][cy])
				continue;
			q.push(pi(cx,cy));
			best[cx][cy] = i;
			mark[cx][cy] = true;
			dist[cx][cy] = dist[x][y] + 1;
		}
	}
	if(!found)
		puts("Impossible");
}

int main() {
	scanf("%d",&n);
	scanf("%d%d%d%d",&ax,&ay,&bx,&by);
	bfs();
	return 0;
}
