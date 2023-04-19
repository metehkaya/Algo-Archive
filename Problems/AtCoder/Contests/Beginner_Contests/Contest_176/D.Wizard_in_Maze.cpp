#include <bits/stdc++.h>
#define maxn 1000
using namespace std;

struct mydata {
	int r,c,d;
};

mydata newData(int r , int c , int d) {
	mydata s;
	s.r = r;
	s.c = c;
	s.d = d;
	return s;
}

bool operator<(const mydata& a , const mydata& b) {
	return a.d > b.d;
}

int n,m,ax,ay,bx,by;
int dist[maxn][maxn];
int dir[4] = {0,1,0,-1};
string s[maxn];
priority_queue<mydata> Q;

int main() {
	scanf("%d%d%d%d%d%d",&n,&m,&ax,&ay,&bx,&by);
	for( int i = 0 ; i < n ; i++ )
		cin >> s[i];
	ax--,ay--,bx--,by--;
	memset(dist,-1,sizeof(dist));
	Q.push(newData(ax,ay,0));
	while(!Q.empty()) {
		mydata temp = Q.top();
		Q.pop();
		int r = temp.r;
		int c = temp.c;
		int d = temp.d;
		dist[r][c] = d;
		if(r == bx && c == by)
			break;
		for( int i = 0 ; i < 4 ; i++ ) {
			int x = r+dir[i];
			int y = c+dir[i^1];
			if(x < 0 || x >= n || y < 0 || y >= m)
				continue;
			if(dist[x][y] != -1 || s[x][y] == '#')
				continue;
			Q.push(newData(x,y,d));
		}
		for( int x = r-2 ; x <= r+2 ; x++ )
			for( int y = c-2 ; y <= c+2 ; y++ ) {
				if(x < 0 || x >= n || y < 0 || y >= m)
					continue;
				if(dist[x][y] != -1 || s[x][y] == '#')
					continue;
				Q.push(newData(x,y,d+1));
			}
	}
	printf("%d\n",dist[bx][by]);
	return 0;
}
