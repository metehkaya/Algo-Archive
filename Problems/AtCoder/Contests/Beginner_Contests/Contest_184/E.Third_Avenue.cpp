#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 2001
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n,m;
int sr,sc,er,ec;

bool mark[26];
int dist[maxn][maxn];
int dir[4] = {0,1,0,-1};

string s[maxn];
vector<pi> tel[26];

int main() {
	cin >> n >> m;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> s[i];
		for( int j = 0 ; j < m ; j++ ) {
			if(s[i][j] == 'S')
				sr = i , sc = j;
			else if(s[i][j] == 'G')
				er = i , ec = j;
			else if(s[i][j] >= 'a' && s[i][j] <= 'z') {
				int c = s[i][j]-'a';
				tel[c].pb(pi(i,j));
			}
		}
	}
	queue<pi> Q;
	memset(dist,-1,sizeof(dist));
	Q.push(pi(sr,sc));
	dist[sr][sc] = 0;
	while(!Q.empty()) {
		pi temp = Q.front();
		Q.pop();
		int r = temp.fi;
		int c = temp.se;
		if(r == er && c == ec) {
			printf("%d\n",dist[r][c]);
			return 0;
		}
		for( int i = 0 ; i < 4 ; i++ ) {
			int x = r + dir[i];
			int y = c + dir[i^1];
			if(x < 0 || x >= n || y < 0 || y >= m)
				continue;
			if(dist[x][y] != -1 || s[x][y] == '#')
				continue;
			dist[x][y] = dist[r][c]+1;
			Q.push(pi(x,y));
		}
		if(s[r][c] >= 'a' && s[r][c] <= 'z') {
			int id = s[r][c]-'a';
			if(!mark[id]) {
				mark[id] = true;
				for( int i = 0 ; i < tel[id].size() ; i++ ) {
					int x = tel[id][i].fi;
					int y = tel[id][i].se;
					if(dist[x][y] != -1)
						continue;
					dist[x][y] = dist[r][c]+1;
					Q.push(pi(x,y));
				}
			}
		}
	}
	puts("-1");
	return 0;
}
