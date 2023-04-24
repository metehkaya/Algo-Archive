#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 102
#define maxm 1002
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int T,n,m;
int bef[maxn];
int dist[maxn];
int edge[maxm];
vector<pi> befs;
vector<pi> dists;
vector<pi> adj[maxn];

void reset() {
	befs.clear();
	dists.clear();
	for( int i = 1 ; i <= n ; i++ )
		adj[i].clear();
	memset(edge, -1, sizeof(edge));
	memset(dist, -1, sizeof(dist));
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&m);
		for( int i = 2 ; i <= n ; i++ ) {
			int val;
			scanf("%d",&val);
			if(val < 0) {
				bef[i] = -val;
				befs.pb( pi( bef[i] , i ) );
			}
			else {
				dist[i] = val;
				dists.pb( pi( dist[i] , i ) );
			}
		}
		for( int i = 1 , x,y ; i <= m ; i++ ) {
			scanf("%d%d",&x,&y);
			adj[x].pb( pi(y,i) );
			adj[y].pb( pi(x,i) );
		}
		dist[1] = 0;
		sort( befs.begin() , befs.end() );
		sort( dists.begin() , dists.end() );
		int currDist = 0 , distIndex = 0;
		for( int i = 0 , j = 0 , cnt = 1 ; i < befs.size() ; i = j ) {
			while( j < befs.size() && befs[i].fi == befs[j].fi )
				j++;
			while( cnt < befs[i].fi ) {
				cnt++;
				currDist = dists[distIndex++].fi;
			}
			currDist++;
			for( int k = i ; k < j ; k++ ) {
				int u = befs[k].se;
				for( int i = 0 ; i < adj[u].size() ; i++ ) {
					int v = adj[u][i].fi;
					int way = adj[u][i].se;
					if( dist[v] != -1 && dist[v] < currDist ) {
						dist[u] = currDist;
						edge[way] = dist[u] - dist[v];
						break;
					}
				}
			}
			cnt += j-i;
		}
		for( int i = 0 ; i < dists.size() ; i++ ) {
			int u = dists[i].se;
			for( int j = 0 ; j < adj[u].size() ; j++ ) {
				int v = adj[u][j].fi;
				int way = adj[u][j].se;
				if( dist[v] < dist[u] ) {
					edge[way] = dist[u] - dist[v];
					break;
				}
			}
		}
		printf("Case #%d: ",tc);
		for( int i = 1 ; i <= m ; i++ ) {
			if( edge[i] == -1 )
				printf("1000000 ");
			else
				printf("%d ", edge[i]);
		}
		puts("");
	}
	return 0;
}
