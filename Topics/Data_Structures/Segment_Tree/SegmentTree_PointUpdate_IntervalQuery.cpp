#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

int n,m;
int ar[maxn];
LL tree[4*maxn];

LL init(int x , int y , int id) {
	if(x == y)
		return tree[id] = ar[x];
	int mid = (x+y) >> 1;
	LL l = init(x,mid,id*2);
	LL r = init(mid+1,y,id*2+1);
	return tree[id] = l+r;
}

LL update(int cx , int cy , int q , int val , int id) {
	if(cy < q || q < cx)
		return tree[id];
	if(cx == cy)
		return tree[id] = val;
	int mid = (cx+cy) >> 1;
	LL l = update(cx,mid,q,val,id*2);
	LL r = update(mid+1,cy,q,val,id*2+1);
	return tree[id] = l+r;
}

LL query(int cx , int cy , int qx , int qy , int id) {
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
			scanf("%d%d",&x,&val);
			update(1,n,x,val,1);
		}
		else {
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,n,x,y,1));
		}
	}
	return 0;
}
