#include <bits/stdc++.h>
#define fi first
#define se second
#define maxh 1503
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int h,w,n,m,ans;
vector<pi> rows[maxh];
vector<pi> cols[maxh];
bool mark[maxh][maxh];

int main() {
	scanf("%d%d%d%d",&h,&w,&n,&m);
	for( int i = 1 ; i <= h ; i++ ) {
		rows[i].pb(pi(0,0));
		rows[i].pb(pi(w+1,0));
	}
	for( int i = 1 ; i <= w ; i++ ) {
		cols[i].pb(pi(0,0));
		cols[i].pb(pi(h+1,0));
	}
	for( int i = 0 , x,y ; i < n ; i++ ) {
		scanf("%d%d",&x,&y);
		rows[x].pb(pi(y,1));
		cols[y].pb(pi(x,1));
	}
	for( int i = 0 , x,y ; i < m ; i++ ) {
		scanf("%d%d",&x,&y);
		rows[x].pb(pi(y,0));
		cols[y].pb(pi(x,0));
	}
	for( int r = 1 ; r <= h ; r++ ) {
		vector<pi> v = rows[r];
		sort(v.begin(),v.end());
		int sz = v.size();
		int last = 0;
		for( int i = 1 ; i < sz ; i++ ) {
			if(v[i].se == 0) {
				if(v[i-1].se == 1)
					for( int l = last+1 ; l < v[i].fi ; l++ )
						mark[r][l] = true;
				last = v[i].fi;
			}
		}
	}
	for( int c = 1 ; c <= w ; c++ ) {
		vector<pi> v = cols[c];
		sort(v.begin(),v.end());
		int sz = v.size();
		int last = 0;
		for( int i = 1 ; i < sz ; i++ ) {
			if(v[i].se == 0) {
				if(v[i-1].se == 1)
					for( int l = last+1 ; l < v[i].fi ; l++ )
						mark[l][c] = true;
				last = v[i].fi;
			}
		}
	}
	for( int i = 1 ; i <= h ; i++ )
		for( int j = 1 ; j <= w ; j++ )
			ans += mark[i][j];
	printf("%d\n",ans);
	return 0;
}
