#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200001
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
typedef pair<int,LL> piLL;

int n,k,m;
pii ar[maxn];
int val[maxn];
piLL tree[4*maxn];

bool comp(const pii& a , const pii& b) {
	return a.se < b.se;
}

piLL query( int x , int y , int rem , int id ) {
	if(x == y)
		return piLL( val[x] , (LL) rem * val[x] );
	int mid = (x + y) >> 1;
	if(tree[id*2].fi < rem) {
		piLL res = query(mid+1,y,rem-tree[id*2].fi,id*2+1);
		res.se += tree[id*2].se;
		return res;
	}
	return query(x,mid,rem,id*2);
}

void update( int x , int y , int q , int val1 , int val2 , int id ) {
	if(y < q || q < x)
		return;
	tree[id].fi += val1;
	tree[id].se += val2;
	if(x == y)
		return;
	int mid = (x + y) >> 1;
	update(x,mid,q,val1,val2,id*2);
	update(mid+1,y,q,val1,val2,id*2+1);
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
	LL total = 0;
	int o = (k+1) / 2;
	for( int i = 1 ; i <= n ; i++ ) {
		total += ar[i].fi.fi;
		update(1,m,ar[i].fi.se,+1,+ar[i].fi.fi,1);
		if(i > k) {
			total -= ar[i-k].fi.fi;
			update(1,m,ar[i-k].fi.se,-1,-ar[i-k].fi.fi,1);
		}
		if(i >= k) {
			piLL res = query(1,m,o,1);
			LL sum1 = (LL) o * res.fi - res.se;
			LL sum2 = total - res.se - (LL) (k-o) * res.fi;
			printf("%lld ",sum1+sum2);
		}
	}
	return 0;
}