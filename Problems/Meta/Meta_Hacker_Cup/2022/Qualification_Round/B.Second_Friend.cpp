#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100
using namespace std;
typedef pair<int,int> pi;

int T,n,m;
bool possible;
string s[maxn];
string ans[maxn];
int cnt[maxn][maxn];
bool mark[maxn][maxn];
int dir[4] = {0,1,0,-1};

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	possible = true;
	memset(cnt,0,sizeof(cnt));
	memset(mark,false,sizeof(mark));
}

void solve() {
	queue<pi> q;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ ) {
			for( int k = 0 ; k < 4 ; k++ ) {
				int r = i+dir[k];
				int c = j+dir[k^1];
				if(r >= 0 && r < n && c >= 0 && c < m && s[r][c] != '#')
					cnt[i][j]++;
			}
			if(cnt[i][j] < 2)
				q.push(pi(i,j)) , mark[i][j] = true;
		}
	while(!q.empty()) {
		pi temp = q.front();
		q.pop();
		int i = temp.fi , j = temp.se;
		for( int k = 0 ; k < 4 ; k++ ) {
			int r = i+dir[k];
			int c = j+dir[k^1];
			if(r >= 0 && r < n && c >= 0 && c < m && s[r][c] != '#') {
				cnt[r][c]--;
				if(!mark[r][c] && cnt[r][c] < 2)
					q.push(pi(r,c)) , mark[r][c] = true;
			}
		}
	}
	for( int i = 0 ; i < n ; i++ ) {
		ans[i] = s[i];
		for( int j = 0 ; j < m ; j++ )
			if(s[i][j] != '#') {
				if(s[i][j] == '^' && mark[i][j])
					possible = false;
				if(mark[i][j])
					ans[i][j] = '.';
				else
					ans[i][j] = '^';
			}
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&m);
		for( int i = 0 ; i < n ; i++ )
			cin >> s[i];
		solve();
		if(!possible)
			printf("Case #%d: Impossible\n",tc);
		else {
			printf("Case #%d: Possible\n",tc);
			for( int i = 0 ; i < n ; i++ )
				cout << ans[i] << endl;
		}
	}
	return 0;
}
