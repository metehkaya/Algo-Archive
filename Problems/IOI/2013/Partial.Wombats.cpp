#include <bits/stdc++.h>
#include "wombats.h"
#define maxm 200
#define maxn 5000
using namespace std;

int n,m;
int*** cost;
bool*** mark;
int edgeH[maxn][maxm];
int edgeV[maxn][maxm];

struct path {
	int r,c,dist;
	path(int _r , int _c , int _dist) {
		r = _r;
		c = _c;
		dist = _dist;
	}
};

bool operator<(const path& a , const path& b) {
	return a.dist > b.dist;
}

void dijkstra(int col) {
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ ) {
			mark[col][i][j] = false;
			cost[col][i][j] = INT_MAX;
		}
	priority_queue<path> heap;
	cost[col][0][col] = 0;
	heap.push(path(0,col,0));
	while(!heap.empty()) {
		path p = heap.top();
		heap.pop();
		int r = p.r;
		int c = p.c;
		if(mark[col][r][c])
			continue;
		mark[col][r][c] = true;
		int dist = p.dist;
		if(c >= 1 && dist+edgeH[r][c-1] < cost[col][r][c-1]) {
			cost[col][r][c-1] = dist+edgeH[r][c-1];
			heap.push(path(r,c-1,dist+edgeH[r][c-1]));
		}
		if(c < m-1 && dist+edgeH[r][c] < cost[col][r][c+1]) {
			cost[col][r][c+1] = dist+edgeH[r][c];
			heap.push(path(r,c+1,dist+edgeH[r][c]));
		}
		if(r < n-1 && dist+edgeV[r][c] < cost[col][r+1][c]) {
			cost[col][r+1][c] = dist+edgeV[r][c];
			heap.push(path(r+1,c,dist+edgeV[r][c]));
		}
	}
}

bool checkCond() {
	return (m <= 2) || (n <= 20 && m <= 20);
}

void init(int R, int C, int H[5000][200], int V[5000][200]) {
	n = R;
	m = C;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m-1 ; j++ )
			edgeH[i][j] = H[i][j];
	for( int i = 0 ; i < n-1 ; i++ )
		for( int j = 0 ; j < m ; j++ )
			edgeV[i][j] = V[i][j];
	cost = new int**[m];
	mark = new bool**[m];
	for( int col = 0 ; col < m ; col++ ) {
		cost[col] = new int*[n];
		mark[col] = new bool*[n];
		for( int i = 0 ; i < n ; i++ ) {
			cost[col][i] = new int[m];
			mark[col][i] = new bool[m];
		}
	}
	if(checkCond())
		for( int i = 0 ; i < m ; i++ )
			dijkstra(i);
}

void changeH(int P, int Q, int W) {
	edgeH[P][Q] = W;
	if(checkCond())
		for( int i = 0 ; i < m ; i++ )
			dijkstra(i);
}

void changeV(int P, int Q, int W) {
	edgeV[P][Q] = W;
	if(checkCond())
		for( int i = 0 ; i < m ; i++ )
			dijkstra(i);
}

int escape(int V1, int V2) {
	int ans;
	if(checkCond())
		ans = cost[V1][n-1][V2];
	else {
		dijkstra(V1);
		ans = cost[V1][n-1][V2];
	}
	return ans;
}

/*
int main() {
	
}
*/
