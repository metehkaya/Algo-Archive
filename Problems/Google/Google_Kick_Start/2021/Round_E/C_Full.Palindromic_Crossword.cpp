#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 1000
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int T,n,m,ans;
string s[maxn];
vector<pi> other[maxn][maxn];

void reset() {
	ans = 0;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			other[i][j].clear();
}

void dealRow(int i) {
	vector<int> v;
	v.pb(-1);
	for( int j = 0 ; j < m ; j++ )
		if(s[i][j] == '#')
			v.pb(j);
	v.pb(m);
	int sz = v.size();
	for( int j = 1 ; j < sz ; j++ ) {
		int x = v[j-1] , y = v[j];
		if(y-x > 2) {
			x++,y--;
			for( int a = x , b = y ; a <= y ; a++ , b-- )
				other[i][a].pb(pi(i,b));
		}
	}
}

void dealCol(int i) {
	vector<int> v;
	v.pb(-1);
	for( int j = 0 ; j < n ; j++ )
		if(s[j][i] == '#')
			v.pb(j);
	v.pb(n);
	int sz = v.size();
	for( int j = 1 ; j < sz ; j++ ) {
		int x = v[j-1] , y = v[j];
		if(y-x >= 2) {
			x++,y--;
			for( int a = x , b = y ; a <= y ; a++ , b-- )
				other[a][i].pb(pi(b,i));
		}
	}
}

void solve() {
	queue<pi> Q;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			if(s[i][j] >= 'A' && s[i][j] <= 'Z')
				Q.push(pi(i,j));
	while(!Q.empty()) {
		pi temp = Q.front();
		Q.pop();
		int r = temp.fi;
		int c = temp.se;
		char ch = s[r][c];
		int sz = other[r][c].size();
		for( int i = 0 ; i < sz ; i++ ) {
			int x = other[r][c][i].fi;
			int y = other[r][c][i].se;
			if(s[x][y] == '.') {
				ans++;
				s[x][y] = ch;
				Q.push(pi(x,y));
			}
		}
	}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&m);
		for( int i = 0 ; i < n ; i++ )
			cin >> s[i];
		for( int i = 0 ; i < n ; i++ )
			dealRow(i);
		for( int i = 0 ; i < m ; i++ )
			dealCol(i);
		solve();
		printf("Case #%d: %d\n",tc,ans);
		for( int i = 0 ; i < n ; i++ )
			cout << s[i] << endl;
	}
	return 0;
}
