#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 300
#define maxv 2000001
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

LL ans;
int T,n,m;
int ar[maxn][maxn];
bool mark[maxn][maxn];
int dir[4] = {0,1,0,-1};
vector<pi> cells[maxv];

void reset() {
	ans = 0;
	memset(mark,0,sizeof(mark));
	for( int i = 0 ; i < maxv ; i++ )
		cells[i].clear();
}

void solve() {
	vector<pi> v;
	for( int val = maxv-1 ; val >= 0 ; val-- ) {
		int sz = cells[val].size();
		for( int i = 0 ; i < sz ; i++ ) {
			int r = cells[val][i].fi;
			int c = cells[val][i].se;
			if(!mark[r][c]) {
				mark[r][c] = true;
				v.pb(pi(r,c));
			}
		}
		sz = v.size();
		vector<pi> nextv;
		for( int i = 0 ; i < sz ; i++ ) {
			int r = v[i].fi;
			int c = v[i].se;
			ans += val - ar[r][c];
			for( int j = 0 ; j < 4 ; j++ ) {
				int x = r+dir[j];
				int y = c+dir[j^1];
				if(x < 0 || x >= n || y < 0 || y >= m)
					continue;
				if(mark[x][y])
					continue;
				mark[x][y] = true;
				nextv.pb(pi(x,y));
			}
		}
		v = nextv;
	}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&m);
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ ) {
				scanf("%d",&ar[i][j]);
				cells[ar[i][j]].pb(pi(i,j));
			}
		solve();
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
