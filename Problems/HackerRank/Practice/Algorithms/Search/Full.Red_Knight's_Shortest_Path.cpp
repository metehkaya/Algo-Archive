#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n,sr,sc,er,ec;
int bef[maxn][maxn];
string ways[6] = {"UL","UR","R","LR","LL","L"};
int dir[6][2]={{-2,-1},{-2,+1},{0,+2},{+2,+1},{+2,-1},{0,-2}};

void bfs() {
	queue<pi> Q;
	memset(bef, -1, sizeof(bef));
	bef[sr][sc] = 6;
	Q.push(pi(sr,sc));
	while(!Q.empty()) {
		pi tmp = Q.front();
		Q.pop();
		int r = tmp.fi;
		int c = tmp.se;
		if(r == er && c == ec)
			break;
		for( int i = 0 ; i < 6 ; i++ ) {
			int x = r + dir[i][0];
			int y = c + dir[i][1];
			if(x < 0 || x >= n || y < 0 || y >= n)
				continue;
			if(bef[x][y] != -1)
				continue;
			bef[x][y] = i;
			Q.push(pi(x,y));
		}
	}
}

void output(int r, int c, int d) {
	if(r == sr && c == sc) {
		printf("%d\n", d);
		return;
	}
	int step = bef[r][c];
	int x = r - dir[step][0];
	int y = c - dir[step][1];
	output(x,y,d+1);
	printf("%s ", ways[step].c_str());
}

int main() {
	scanf("%d%d%d%d%d",&n,&sr,&sc,&er,&ec);
	bfs();
	if(bef[er][ec] == -1)
		puts("Impossible");
	else
		output(er,ec,0);
	return 0;
}
