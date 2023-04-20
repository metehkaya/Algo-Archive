#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200001
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

int n,k,m;
pii ar[maxn];
int val[maxn];
int tree[4*maxn];

bool comp(const pii& a , const pii& b) {
	return a.se < b.se;
}

int query( int x , int y , int rem , int id ) {
	if(x == y)
		return val[x];
	int mid = (x + y) >> 1;
	if(tree[id*2] < rem)
		return query(mid+1,y,rem-tree[id*2],id*2+1);
	return query(x,mid,rem,id*2);
}

void update( int x , int y , int q , int val , int id ) {
	if(y < q || q < x)
		return;
	tree[id] += val;
	if(x == y)
		return;
	int mid = (x + y) >> 1;
	update(x,mid,q,val,id*2);
	update(mid+1,y,q,val,id*2+1);
}

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 1 , x ; i <= n ; i++ ) {
		scanf("%d",&x);
		ar[i] = pii( pi(x,0) , i );
	}
	sort( ar+1 , ar+n+1 );
	for( int i = 1 , j = 1 ; i <= n ; i = j ) {
		val[++m] = ar[i].fi.fi;
		while( j <= n && ar[i].fi.fi == ar[j].fi.fi )
			ar[j++].fi.se = m;
	}
	sort( ar+1 , ar+n+1 , comp );
	int o = (k+1) / 2;
	for( int i = 1 ; i <= n ; i++ ) {
		update(1,m,ar[i].fi.se,+1,1);
		if(i > k)
			update(1,m,ar[i-k].fi.se,-1,1);
		if(i >= k)
			printf("%d ",query(1,m,o,1));
	}
	return 0;
}