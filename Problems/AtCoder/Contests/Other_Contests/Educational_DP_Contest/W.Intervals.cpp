#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 2000003
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int n,m;
LL total;
LL tree[4*maxn];
LL lazy[4*maxn];
vector<pi> v[maxn];

void proc(int tx, int ty, int id) {
	if(lazy[id]) {
		tree[id] += lazy[id];
		if(tx != ty) {
			lazy[2*id] += lazy[id];
			lazy[2*id+1] += lazy[id];
		}
		lazy[id] = 0;
	}
}

LL query(int tx, int ty, int qx, int qy, int id) {
	proc(tx, ty, id);
	if(ty < qx || qy < tx)
		return LLONG_MAX;
	if(qx <= tx && ty <= qy)
		return tree[id];
	int mid = (tx + ty) >> 1;
	LL left = query(tx, mid, qx, qy, id*2);
	LL right = query(mid+1, ty, qx, qy, id*2+1);
	return min(left, right);
}

LL update(int tx, int ty, int qx, int qy, LL val, int id) {
	proc(tx, ty, id);
	if(ty < qx || qy < tx)
		return tree[id];
	if(qx <= tx && ty <= qy) {
		lazy[id] = val;
		proc(tx, ty, id);
		return tree[id];
	}
	int mid = (tx + ty) >> 1;
	LL left = update(tx, mid, qx, qy, val, id*2);
	LL right = update(mid+1, ty, qx, qy, val, id*2+1);
	return tree[id] = min(left, right);
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < m ; i++ ) {
		int l,r,val;
		scanf("%d%d%d",&l,&r,&val);
		total += val;
		v[r].pb(pi(l,val));
	}
	for( int i = 1 ; i <= n ; i++ ) {
		LL val = query(0, n, 0, i-1, 1);
		update(0, n, i, i, val, 1);
		for( int j = 0 ; j < (int) v[i].size() ; j++ )
			update(0, n, 0, v[i][j].fi-1, v[i][j].se, 1);
	}
	printf("%lld\n",total-query(0, n, 0, n, 1));
	return 0;
}
