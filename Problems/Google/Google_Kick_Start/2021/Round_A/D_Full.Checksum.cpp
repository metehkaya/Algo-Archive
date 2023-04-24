#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 500
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

int T,n,ans;
int dad[2*maxn];
int lvl[2*maxn];
vector<pii> edges;

void reset() {
	ans = 0;
	edges.clear();
	for( int i = 0 ; i < 2*maxn ; i++ )
		lvl[i] = 0 , dad[i] = i;
}

int findDad(int u) {
	if(u == dad[u])
		return u;
	return dad[u] = findDad(dad[u]);
}

void merge(int u , int v) {
	if(lvl[u] > lvl[v])
		swap(u,v);
	dad[u] = v;
	if(lvl[u] == lvl[v])
		lvl[v]++;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		int idle;
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < n ; j++ )
				scanf("%d",&idle);
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 , x ; j < n ; j++ ) {
				scanf("%d",&x);
				if(x)
					edges.pb(pii(x,pi(i,j+n)));
			}
		for( int i = 0 ; i < 2*n ; i++ )
			scanf("%d",&idle);
		int m = edges.size();
		sort(edges.begin(),edges.end());
		for( int i = m-1 ; i >= 0 ; i-- ) {
			int w = edges[i].fi;
			int u = edges[i].se.fi;
			int v = edges[i].se.se;
			u = findDad(u);
			v = findDad(v);
			if(u == v)
				ans += w;
			else
				merge(u,v);
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
