#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
typedef long long LL;

int n;
int h[maxn];
int v[maxn];
LL tree[4*maxn];

void update(int tx, int ty, int q, LL val, int id) {
	if(q < tx || ty < q)
		return;
	tree[id] = max( tree[id] , val );
	if(tx == ty)
		return;
	int mid = (tx + ty) >> 1;
	update(tx, mid, q, val, id*2);
	update(mid+1, ty, q, val, id*2+1);
}

LL query(int tx, int ty, int qx, int qy, int id) {
	if(qy < tx || ty < qx)
		return 0;
	if(qx <= tx && ty <= qy)
		return tree[id];
	int mid = (tx + ty) >> 1;
	return max( query(tx,mid,qx,qy,id*2) , query(mid+1,ty,qx,qy,id*2+1) );
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&h[i]);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&v[i]);
	for( int i = 1 ; i <= n ; i++ ) {
		LL val = query(1,n,1,h[i],1) + v[i];
		update(1,n,h[i],val,1);
	}
	printf("%lld\n",tree[1]);
	return 0;
}
