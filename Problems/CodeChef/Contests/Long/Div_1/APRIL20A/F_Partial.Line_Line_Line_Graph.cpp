#include <bits/stdc++.h>
#define maxn 2001
#define pb push_back
using namespace std;

int n,m,k;
int ans,qh,qt;

int q[maxn];
int dad[maxn];
int base[maxn];
int match[maxn];

bool inq[maxn];
bool inb[maxn];

vector<int> G[maxn];

int findLCA( int root , int u , int v ) {
	static bool inp[maxn];
	memset( inp , 0 , sizeof(inp) );
	while(true) {
		inp[ u = base[u] ] = true;
		if( u == root )
			break;
		u = dad[ match[u] ];
	}
	while(true) {
		if( inp[ v=base[v] ] )
			return v;
		else
			v = dad[ match[v] ];
	}
}

void mark( int lca , int u ) {
	while( base[u] != lca ) {
		int v = match[u];
		inb[ base[u] ] = inb[ base[v] ] = true;
		u = dad[v];
		if( base[u] != lca )
			dad[u] = v;
	}
}

void blossom( int s , int u , int v ) {
	int lca = findLCA(s,u,v);
	memset( inb , 0 , sizeof(inb) );
	mark(lca,u);
	mark(lca,v);
	if( base[u] != lca )
		dad[u] = v;
	if( base[v] != lca )
		dad[v] = u;
	for( int u = 0 ; u < n ; u++)
		if( inb[ base[u] ] ) {
			base[u] = lca;
			if(!inq[u])
				inq[ q[++qt] = u ] = true;
		}
}

int findAugPath(int s) {
	memset( inq , 0 , sizeof(inq) );
	memset( dad , -1 , sizeof(dad) );
	for( int i = 0 ; i < n ; i++)
		base[i] = i;
	inq[ q[ qh=qt=0 ] = s ] = true;
	while( qh <= qt ) {
		int u = q[qh++];
		for( int i = 0 ; i < (int) G[u].size() ; i++ ) {
			int v = G[u][i];
			if( base[u] != base[v] && match[u] != v ) {
				if( ( v == s ) || ( match[v] != -1 && dad[ match[v] ] != -1 ) )
					blossom(s,u,v);
				else if( dad[v] == -1 ) {
					dad[v] = u;
					if( match[v] == -1 )
						return v;
					else if( !inq[match[v]] )
						inq[ q[++qt] = match[v] ] = true;
				}
			}
		}
	}
	return -1;
}

int augPath( int s , int t ) {
	int u=t , v , w;
	while( u != -1 ) {
		v = dad[u];
		w = match[v];
		match[v] = u;
		match[u] = v;
		u = w;
	}
	return t != -1;
}

void solve() {
	memset( match , -1 , sizeof(match) );
	for( int i = 0 ; i < n ; i++ )
		if( match[i] == -1 )
			ans += augPath( i , findAugPath(i) );
	printf("%d\n",ans);
}

void input() {
	scanf("%d%d%d",&n,&m,&k);
	if(k > 1)
		exit(0);
	for( int i = 1 ; i <= m ; i++ ) {
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		G[u].pb(v);
		G[v].pb(u);
	}
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < 5 ; j++ )
			random_shuffle( G[i].begin() , G[i].end() );
}

int main() {
	srand(time(NULL));
	input();
	solve();
	return 0;
}
