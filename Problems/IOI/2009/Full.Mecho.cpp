#include <bits/stdc++.h>
#define maxn 805
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pi;

int n,s,ans;
int mr,mc,dr,dc;
char str[maxn][maxn];
int dist[maxn][maxn];
int distBee[maxn][maxn];
int dir[4] = {0,1,0,-1};

void bfsBee() {
	queue<pi> Q;
	memset(distBee,-1,sizeof(distBee));
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= n ; j++ )
			if(str[i][j] == 'H') {
				Q.push(pi(i,j));
				distBee[i][j] = 0;
			}
	while(!Q.empty()) {
		pi temp = Q.front();
		Q.pop();
		int r = temp.fi;
		int c = temp.se;
		for( int i = 0 ; i < 4 ; i++ ) {
			int x = r + dir[i];
			int y = c + dir[i^1];
			if(x < 1 || x > n || y < 1 || y > n)
				continue;
			if(distBee[x][y] != -1 || (str[x][y] != 'G' && str[x][y] != 'M'))
				continue;
			Q.push(pi(x,y));
			distBee[x][y] = distBee[r][c] + s;
		}
	}
}

bool bfs(int d) {
	if(distBee[mr][mc] != -1 && distBee[mr][mc] <= s*d)
		return false;
	queue<pi> Q;
	memset(dist,-1,sizeof(dist));
	Q.push(pi(mr,mc));
	dist[mr][mc] = s*d;
	while(!Q.empty()) {
		pi temp = Q.front();
		Q.pop();
		int r = temp.fi;
		int c = temp.se;
		if(r == dr && c == dc)
			return true;
		for( int i = 0 ; i < 4 ; i++ ) {
			int x = r + dir[i];
			int y = c + dir[i^1];
			if(x < 1 || x > n || y < 1 || y > n)
				continue;
			if(dist[x][y] != -1 || (str[x][y] != 'G' && str[x][y] != 'D'))
				continue;
			if(distBee[x][y] != -1 && dist[r][c]+1 >= distBee[x][y])
				continue;
			Q.push(pi(x,y));
			dist[x][y] = dist[r][c] + 1;
		}
	}
	return false;
}

int main() {
	scanf("%d%d",&n,&s);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%s",str[i]+1);
		for( int j = 1 ; j <= n ; j++ )
			if(str[i][j] == 'M')
				mr = i , mc = j;
			else if(str[i][j] == 'D')
				dr = i , dc = j;
	}
	bfsBee();
	ans = -1;
	int l = 0 , r = n*n;
	while(l <= r) {
		int m = (l+r) >> 1;
		if(bfs(m))
			ans = m , l = m+1;
		else
			r = m-1;
	}
	printf("%d\n",ans);
	return 0;
}
