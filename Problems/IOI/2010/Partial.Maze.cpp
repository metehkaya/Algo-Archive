#include <bits/stdc++.h>
#define maxn 203
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

const int TC = 10;
const int LIM = 20;
const int TIMES = 100;
int N[TC] = {6,100,100,100,100,11,20,20,11,200};
int M[TC] = {10,100,100,100,100,11,20,20,21,200};

int n,m,best;
char s[maxn][maxn];
char out[maxn][maxn];
int befr[maxn][maxn];
int befc[maxn][maxn];
int dist[maxn][maxn];
int dir[4] = {0,1,0,-1};

bool checkAdj(int r , int c , int r0 , int c0 , int d) {
	for( int i = 0 ; i < 4 ; i++ ) {
		int r2 = r+dir[i];
		int c2 = c+dir[i^1];
		if(r2 > 0 && r2 < n-1 && c2 > 0 && c2 < m-1)
			if(r2 != r0 || c2 != c0)
				if(dist[r2][c2] != -1 && dist[r2][c2] <= d)
					return false;
	}
	return true;
}

void bfs(int rsrc , int csrc , int distSrc , int bfsc) {
	dist[rsrc][csrc] = distSrc;
	queue<pi> Q;
	vector<pi> q;
	Q.push(pi(rsrc,csrc));
	while(!Q.empty()) {
		pi p = Q.front();
		Q.pop();
		q.pb(p);
		int r = p.fi , c = p.se;
		for( int i = 0 ; i < 4 ; i++ ) {
			int r2 = r+dir[i];
			int c2 = c+dir[i^1];
			if(r2 > 0 && r2 < n-1 && c2 > 0 && c2 < m-1)
				if(dist[r2][c2] == -1 && s[r2][c2] == '#')
					if(checkAdj(r2,c2,r,c,dist[r][c])) {
						befr[r2][c2] = r;
						befc[r2][c2] = c;
						Q.push(pi(r2,c2));
						dist[r2][c2] = dist[r][c] + 1;
					}
		}
	}
	vector<pi> bests;
	int qsz = q.size();
	int qBestDist = -1;
	for( int i = 0 ; i < qsz ; i++ ) {
		int r = q[i].fi;
		int c = q[i].se;
		if(dist[r][c] > qBestDist) {
			qBestDist = dist[r][c];
			bests.clear();
			bests.pb(pi(r,c));
		}
		else if(dist[r][c] == qBestDist)
			bests.pb(pi(r,c));
	}
	if(qsz == 1 || bfsc == LIM) {
		if(qBestDist > best) {
			best = qBestDist;
			for( int i = 0 ; i < n ; i++ )
				for( int j = 0 ; j < m ; j++ )
					out[i][j] = s[i][j];
			int sz = bests.size();
			int id = rand() % sz;
			int r = bests[id].fi;
			int c = bests[id].se;
			while(dist[r][c] > 0) {
				out[r][c] = '.';
				int row = r , col = c;
				r = befr[row][col];
				c = befc[row][col];
			}
			out[r][c] = '.';
		}
	}
	else {
		int sz = bests.size();
		int id = rand() % sz;
		int rdest = bests[id].fi;
		int cdest = bests[id].se;
		memset(dist,-1,sizeof(dist));
		int r = rdest , c = cdest , d = qBestDist;
		while(d >= 0) {
			dist[r][c] = d;
			int row = r , col = c;
			r = befr[row][col];
			c = befc[row][col];
			d--;
		}
		bfs(rdest,cdest,qBestDist,bfsc+1);
	}
}

void reset(int tc) {
	best = 0;
	n = N[tc];
	m = M[tc];
}

string getInTxt(int tc) {
	tc++;
	string txt = "fieldA.txt";
	if(tc < 10)
		txt[5] = '0'+tc;
	return txt;
}

string getOutTxt(int tc) {
	tc++;
	string txt = "mazeA.txt";
	if(tc < 10)
		txt[4] = '0'+tc;
	return txt;
}

void testcase(int tc , bool first) {
	if(first) {
		reset(tc);
		string inTxt = getInTxt(tc);
		freopen(inTxt.c_str(),"r",stdin);
		for( int i = 0 ; i < n ; i++ )
			scanf("%s",s[i]);
	}
	for( int j = 1 ; j < m-1 ; j++ ) {
		if(s[0][j] == '#') {
			memset(dist,-1,sizeof(dist));
			bfs(0,j,0,1);
		}
		if(s[n-1][j] == '#') {
			memset(dist,-1,sizeof(dist));
			bfs(n-1,j,0,1);
		}
	}
	for( int i = 1 ; i < n-1 ; i++ ) {
		if(s[i][0] == '#') {
			memset(dist,-1,sizeof(dist));
			bfs(i,0,0,1);
		}
		if(s[i][m-1] == '#') {
			memset(dist,-1,sizeof(dist));
			bfs(i,m-1,0,1);
		}
	}
	string outTxt = getOutTxt(tc);
	freopen(outTxt.c_str(),"w",stdout);
	for( int i = 0 ; i < n ; i++ ) {
		for( int j = 0 ; j < m ; j++ )
			printf("%c",out[i][j]);
		puts("");
	}
}

int main() {
	srand(time(NULL));
	for( int tc = 0 ; tc < TC ; tc++ )
		for( int i = 0 ; i < TIMES ; i++ )
			testcase(tc,i==0);
	return 0;
}
