#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;

int T,n;
int dist[maxn];

void bfs() {
	queue<int> Q;
	memset(dist,-1,sizeof(dist));
	Q.push(0);
	dist[0] = 0;
	while(!Q.empty()) {
		int n = Q.front();
		Q.pop();
		if(n+1 < maxn && dist[n+1] == -1) {
			Q.push(n+1);
			dist[n+1] = dist[n]+1;
		}
		for( int i = 2 ; i <= n && n*i < maxn ; i++ )
			if(dist[n*i] == -1) {
				Q.push(n*i);
				dist[n*i] = dist[n]+1;
			}
	}
}

int main() {
	bfs();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		printf("%d\n",dist[n]);
	}
	return 0;
}
