#include <bits/stdc++.h>
#define maxn 101
#define maxk 5001
using namespace std;

struct data {
	int x,st,d;
};

data newData(int x , int st , int d) {
	data temp;
	temp.x = x;
	temp.st = st;
	temp.d = d;
	return temp;
}

bool operator<(const data &a , const data &b) {
	return a.d > b.d;
}

int T,n,m,k;
int s[maxk];
int e[maxk];
int G[maxn][maxn];
bool mark[maxk][4];
priority_queue<data> pq;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	while(!pq.empty())
		pq.pop();
	memset(G,-1,sizeof(G));
	memset(mark,false,sizeof(mark));
	for( int i = 0 ; i < maxn ; i++ )
		G[i][i] = 0;
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d%d",&n,&m,&k);
		for( int i = 0 , a,b,c ; i < m ; i++ ) {
			scanf("%d%d%d",&a,&b,&c);
			if(G[a][b] == -1 || c < G[a][b])
				G[a][b] = G[b][a] = c;
		}
		for( int i = 1 ; i <= k ; i++ )
			scanf("%d%d",&s[i],&e[i]);
		for( int l = 1 ; l <= n ; l++ )
			for( int i = 1 ; i <= n ; i++ )
				for( int j = 1 ; j <= n ; j++ )
					if(G[i][l] != -1 && G[l][j] != -1)
						if(G[i][j] == -1 || G[i][l] + G[l][j] < G[i][j])
							G[i][j] = G[j][i] = G[i][l] + G[l][j];
		int ans = -1;
		s[0] = e[0] = 1;
		pq.push(newData(0,0,0));
		while(!pq.empty()) {
			data temp = pq.top();
			pq.pop();
			int x = temp.x;
			int st = temp.st;
			int d = temp.d;
			if(mark[x][st])
				continue;
			if(x == k && (st == 0 || st == 2)) {
				ans = d;
				break;
			}
			mark[x][st] = true;
			int city , y = x+1 , z=x+2;
			if(st == 0) {
				city = e[x];
				if(G[city][s[y]] != -1 && !mark[y][1])
					pq.push(newData(y,1,d+G[city][s[y]]));
			}
			else if(st == 1) {
				city = s[x];
				if(G[city][e[x]] != -1 && !mark[x][0])
					pq.push(newData(x,0,d+G[city][e[x]]));
				if(G[city][s[y]] != -1 && !mark[x][3])
					pq.push(newData(x,3,d+G[city][s[y]]));
			}
			else if(st == 2) {
				city = e[x];
				if(G[city][e[y]] != -1 && !mark[y][0])
					pq.push(newData(y,0,d+G[city][e[y]]));
				if(G[city][s[z]] != -1 && !mark[y][3])
					pq.push(newData(y,3,d+G[city][s[z]]));
			}
			else {
				city = s[y];
				if(G[city][e[x]] != -1 && !mark[x][2])
					pq.push(newData(x,2,d+G[city][e[x]]));
			}
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
