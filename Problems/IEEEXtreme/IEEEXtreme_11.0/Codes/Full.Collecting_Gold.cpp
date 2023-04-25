#include <bits/stdc++.h>
#define maxk 16
#define maxn 20003
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

struct data {
	LL to , weight;
	LL len;
	data( LL _to , LL _weight , LL _len ) {
		to = _to;
		weight = _weight;
		len = _len;
	}
};

bool operator<( const data &a , const data &b ) {
	if( a.len != b.len )
		return a.len > b.len;
	return a.weight < b.weight;
}

LL n,m,s,e;
LL ar[maxn];
LL val[maxn];
LL mult[maxk];

bool mark[maxn];

map<LL,LL> hashh;
vector<pi> adj[maxn];
priority_queue<data> heap;

LL findVal( LL w ) {
	for( LL i = maxk - 1 ; i >= 0 ; i-- )
		if( w >= mult[i] )
			return i;
	return -1;
}

void findPrimes() {
	mult[0] = 1;
	mult[1] = mult[0] * 2;
	mult[2] = mult[1] * 3;
	mult[3] = mult[2] * 5;
	mult[4] = mult[3] * 7;
	mult[5] = mult[4] * 11;
	mult[6] = mult[5] * 13;
	mult[7] = mult[6] * 17;
	mult[8] = mult[7] * 19;
	mult[9] = mult[8] * 23;
	mult[10] = mult[9] * 29;
	mult[11] = mult[10] * 31;
	mult[12] = mult[11] * 37;
	mult[13] = mult[12] * 41;
	mult[14] = mult[13] * 43;
	mult[15] = mult[14] * 47;
}

void sssp() {
	
	heap.push( data( s , val[s] , 0 ) );
	
	while( !heap.empty() ) {
		
		data tmp = heap.top();
		heap.pop();
		
		LL node = tmp.to;
		LL sum = tmp.weight;
		LL length = tmp.len;
		
		if( node == e ) {
			cout << sum << endl;
			return;
		}
		
		if( mark[node] )
			continue;
		mark[node] = true;
		
		for( LL i = 0 ; i < adj[node].size() ; i++ )
			if( !mark[ adj[node][i].fi ] )
				heap.push( data( adj[node][i].fi , sum + val[ adj[node][i].fi ] , length + adj[node][i].se ) );
		
	}
	
}

int main() {
	
	findPrimes();
	
	cin >> n >> m;
	for( LL i = 1 ; i <= n ; i++ ) {
		cin >> ar[i];
		hashh[ ar[i] ] = i;
		val[i] = findVal( ar[i] );
	}
	for( LL i = 1 , x , y , z ; i <= m ; i++ ) {
		cin >> x >> y >> z;
		x = hashh[x] , y = hashh[y];
		adj[x].pb( pi( y , z ) );
		adj[y].pb( pi( x , z ) );
	}
	
	s = 1;
	for( LL i = 2 ; i <= n ; i++ )
		if( ar[i] < ar[s] )
			s = i;
	
	e = 1;
	for( LL i = 2 ; i <= n ; i++ )
		if( ar[i] > ar[e] )
			e = i;
	
	sssp();
	
	return 0;

}
