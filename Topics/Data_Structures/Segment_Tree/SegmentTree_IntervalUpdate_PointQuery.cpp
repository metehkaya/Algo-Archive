#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

int n,m;
int ar[maxn];
LL tree[4*maxn];

void init(int x , int y , int id) {
	if(x == y) {
		tree[id] = ar[x];
		return;
	}
	int mid = (x+y) >> 1;
	init(x,mid,id*2);
	init(mid+1,y,id*2+1);
}

void update(int cx , int cy , int qx , int qy , int val , int id) {
	if(cy < qx || qy < cx)
		return;
	if(qx <= cx && cy <= qy) {
		tree[id] += val;
		return;
	}
	int mid = (cx+cy) >> 1;
	update(cx,mid,qx,qy,val,id*2);
	update(mid+1,cy,qx,qy,val,id*2+1);
}

LL query(int cx , int cy , int q , int id) {
	if(cy < q || q < cx)
		return 0;
	if(cx == cy)
		return tree[id];
	int mid = (cx+cy) >> 1;
	LL l = query(cx,mid,q,id*2);
	LL r = query(mid+1,cy,q,id*2+1);
	return l+r+tree[id];
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
			scanf("%d",&x);
			printf("%lld\n",query(1,n,x,1));
		}
	}
	return 0;
}
