#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 800001
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int T,n,m,ans;
int p[maxn];
int h[maxn];
int x[3*maxn];
pi dp1[3*maxn];
pi dp2[3*maxn];
map<int,int> id;
vector<pi> v[3*maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	for( int i = 1 ; i <= m ; i++ )
		v[i].clear();
	m = 0;
	ans = 0;
	id.clear();
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ ) {
			scanf("%d%d",&p[i],&h[i]);
			id[p[i]] = -1;
			id[p[i]-h[i]] = -1;
			id[p[i]+h[i]] = -1;
		}
		map<int,int>::iterator it;
		for( it = id.begin() ; it != id.end() ; it++ ) {
			it->second = ++m;
			x[m] = it->first;
		}
		for( int i = 1 ; i <= n ; i++ ) {
			int a = id[p[i]-h[i]];
			int b = id[p[i]];
			int c = id[p[i]+h[i]];
			v[a].pb(pi(b,i));
			v[b].pb(pi(c,i));
		}
		for( int i = m ; i >= 1 ; i-- ) {
			dp1[i] = dp2[i] = pi(0,0);
			int pos = x[i];
			for( int j = 0 ; j < v[i].size() ; j++ ) {
				int nxt = v[i][j].fi;
				int id = v[i][j].se;
				int nxtPos = x[nxt];
				int len = nxtPos - pos;
				int take = (dp1[nxt].se != id) ? dp1[nxt].fi : dp2[nxt].fi;
				int total = len + take;
				if(total > dp1[i].fi) {
					dp2[i] = dp1[i];
					dp1[i] = pi(total,id);
				}
				else if(total > dp2[i].fi)
					dp2[i] = pi(total,id);
			}
			ans = max(ans,dp1[i].fi);
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
