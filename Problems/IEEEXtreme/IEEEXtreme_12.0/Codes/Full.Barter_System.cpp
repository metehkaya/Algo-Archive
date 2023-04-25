#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 20003
#define mod 998244353
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int n,m;
int goo[maxn];
int mark[maxn];
string label[maxn];
vector<pi> adj[maxn];
map<string,int> hashh;

int calcPow( LL x , int y , LL modd ) {
	if( !y )
		return 1;
	LL v = calcPow( x , y / 2 , modd );
	v = (v * v) % modd;
	if( y & 1 )
		v = (v * x) % modd;
	return v;
}

void dfs( int node , int root , LL v ) {
	mark[node] = root;
	goo[node] = v;
	for( int i = 0 ; i < (int) adj[node].size() ; i++ ) {
		int to = adj[node][i].fi;
		if( !mark[to] )
			dfs( to , root , (v * adj[node][i].se) % mod );
	}
}

int main() {
	scanf( "%d" , &m );
	for( int i = 1 , val ; i <= m ; i++ ) {
		string str1,str2;
		cin >> str1 >> str2 >> val;
		int a = hashh[str1];
		if( !a )
			a = hashh[str1] = ++n;
		int b = hashh[str2];
		if( !b )
			b = hashh[str2] = ++n;
		adj[b].pb( pi( a , val ) );
		adj[a].pb( pi( b , calcPow( val , mod - 2 , mod ) ) );
	}
	for( int i = 1 ; i <= n ; i++ )
		if( !mark[i] )
			dfs( i , i , 1 );
	scanf( "%d" , &m );
	for( int i = 1 ; i <= m ; i++ ) {
		string str1 , str2;
		cin >> str1 >> str2;
		if( hashh.find( str1 ) == hashh.end() || hashh.find( str2 ) == hashh.end() )
			puts( "-1" );
		else {
			int a = hashh[str1] , b = hashh[str2];
			if( mark[a] != mark[b] )
				puts( "-1" );
			else {
				int v = ( (LL) calcPow( goo[b] , mod - 2 , mod ) * goo[a] ) % mod;
				printf( "%d\n" , v );
			}
		}
	}
	return 0;
}