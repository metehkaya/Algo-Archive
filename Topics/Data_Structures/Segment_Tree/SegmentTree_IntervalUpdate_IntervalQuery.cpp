#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

int n,m;
int ar[maxn];
LL tree[4*maxn];
LL lazy[4*maxn];

LL init(int x , int y , int id) {
	if(x == y)
		return tree[id] = ar[x];
	int mid = (x+y) >> 1;
	tree[id] += init(x,mid,id*2);
	tree[id] += init(mid+1,y,id*2+1);
	return tree[id];
}

LL update(int cx , int cy , int qx , int qy , LL val , int id) {
	if(lazy[id]) {
		LL len = cy-cx+1;
		tree[id] += len*lazy[id];
		if(cx != cy) {
			lazy[id*2] += lazy[id];
			lazy[id*2+1] += lazy[id];
		}
		lazy[id] = 0;
	}
	if(cy < qx || qy < cx)
		return tree[id];
	if(qx <= cx && cy <= qy) {
		LL len = cy-cx+1;
		tree[id] += len*val;
		if(cx != cy) {
			lazy[id*2] += val;
			lazy[id*2+1] += val;
		}
		return tree[id];
	}
	int mid = (cx+cy) >> 1;
	tree[id] = 0;
	tree[id] += update(cx,mid,qx,qy,val,id*2);
	tree[id] += update(mid+1,cy,qx,qy,val,id*2+1);
	return tree[id];
}

LL query(int cx , int cy , int qx , int qy , int id) {
	if(lazy[id]) {
		LL len = cy-cx+1;
		tree[id] += len*lazy[id];
		if(cx != cy) {
			lazy[id*2] += lazy[id];
			lazy[id*2+1] += lazy[id];
		}
		lazy[id] = 0;
	}
	if(cy < qx || qy < cx)
		return 0;
	if(qx <= cx && cy <= qy)
		return tree[id];
	int mid = (cx+cy) >> 1;
	LL l = query(cx,mid,qx,qy,id*2);
	LL r = query(mid+1,cy,qx,qy,id*2+1);
	return l+r;
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	init(1,n,1);
	for( int i = 0 , t,x,y,val ; i < m ; i++ ) {
		scanf("%d",&t);
		if(t == 0) {
			scanf("%d%d%d",&x,&y,&val);
			update(1,n,x,y,val,1);
		}
		else {
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,n,x,y,1));
		}
	}
	return 0;
}
