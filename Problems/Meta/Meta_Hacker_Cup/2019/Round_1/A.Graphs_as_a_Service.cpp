#include <bits/stdc++.h>
#define maxn 51
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

int T,n,m;
vector<pii>E;
int dist[maxn][maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	E.clear();
	memset(dist,-1,sizeof(dist));
	for( int i = 1 ; i < maxn ; i++ )
		dist[i][i] = 0;
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&m);
		for( int i = 0 , x , y , z ; i < m ; i++ ) {
			scanf("%d%d%d",&x,&y,&z);
			E.pb(pii(pi(x,y),z));
			dist[x][y] = dist[y][x] = z;
		}
		for( int k = 1 ; k <= n ; k++ )
			for( int i = 1 ; i <= n ; i++ )
				for( int j = 1 ; j <= n ; j++ )
					if(dist[i][k] != -1 && dist[k][j] != -1) {
						int val = dist[i][k] + dist[k][j];
						if(dist[i][j] == -1 || val < dist[i][j])
							dist[i][j] = val;
					}
		bool ok = true;
		for( int i = 0 ; ok && i < m ; i++ ) {
			int x = E[i].fi.fi;
			int y = E[i].fi.se;
			int z = E[i].se;
			if(dist[x][y] != z || dist[y][x] != z)
				ok = false;
		}
		if(ok) {
			printf("Case #%d: %d\n",tc,m);
			for( int i = 0 ; i < m ; i++ )
				printf("%d %d %d\n",E[i].fi.fi,E[i].fi.se,E[i].se);
		}
		else
			printf("Case #%d: Impossible\n",tc);
	}
	return 0;
}
