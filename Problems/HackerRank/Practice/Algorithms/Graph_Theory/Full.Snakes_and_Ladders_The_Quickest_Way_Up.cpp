#include <bits/stdc++.h>
#define fi first
#define se second
#define maxs 101
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int T,n,m;
int ep[maxs];
int dist[maxs];

void reset() {
	memset(ep,-1,sizeof(ep));
	memset(dist,-1,sizeof(dist));
}

void read() {
	scanf("%d",&n);
	for( int i = 0 , x , y ; i < n ; i++ ) {
		scanf("%d%d",&x,&y);
		ep[x] = y;
	}
	scanf("%d",&m);
	for( int i = 0 , x , y ; i < m ; i++ ) {
		scanf("%d%d",&x,&y);
		ep[x] = y;
	}
}

int bfs() {
	queue<int>Q;
	dist[1] = 0;
	Q.push(1);
	while(!Q.empty()) {
		int node = Q.front();
		Q.pop();
		if(node == 100)
			return dist[node];
		for( int i = 1 ; i <= 6 ; i++ ) {
			int to = node + i;
			if(to < maxs) {
				if(ep[to] != -1)
				    to = ep[to];
				if(dist[to] == -1) {
				    dist[to] = dist[node] + 1;
				    Q.push(to);
				}
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		read();
		printf("%d\n",bfs());
	}
	return 0;
}
