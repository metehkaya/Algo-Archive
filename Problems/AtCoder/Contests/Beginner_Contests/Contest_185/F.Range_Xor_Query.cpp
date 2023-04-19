#include <bits/stdc++.h>
#define maxk 30
#define maxn 300001
using namespace std;

int n,m;
int ar[maxn];
bool tree[maxk][4*maxn];

void init(int x , int y , int id) {
	if(x == y) {
		for( int i = 0 ; i < maxk ; i++ )
			if(ar[x] & (1<<i))
				tree[i][id] = 1;
		return;
	}
	int mid = (x+y) >> 1;
	init(x,mid,2*id);
	init(mid+1,y,2*id+1);
	for( int i = 0 ; i < maxk ; i++ )
		tree[i][id] = (tree[i][2*id] ^ tree[i][2*id+1]);
}

void update(int cx , int cy , int q , int val , int id) {
	if(cy < q || q < cx)
		return;
	if(cx == cy) {
		for( int i = 0 ; i < maxk ; i++ )
			if(val & (1<<i))
				tree[i][id] ^= 1;
		return;
	}
	int mid = (cx+cy) >> 1;
	update(cx,mid,q,val,2*id);
	update(mid+1,cy,q,val,2*id+1);
	for( int i = 0 ; i < maxk ; i++ )
		tree[i][id] = (tree[i][2*id] ^ tree[i][2*id+1]);
}

int query(int cx , int cy , int qx , int qy , int id) {
	if(qy < cx || cy < qx)
		return 0;
	if(qx <= cx && cy <= qy) {
		int val = 0;
		for( int i = 0 ; i < maxk ; i++ )
			if(tree[i][id])
				val |= (1<<i);
		return val;
	}
	int mid = (cx+cy) >> 1;
	int l = query(cx,mid,qx,qy,2*id);
	int r = query(mid+1,cy,qx,qy,2*id+1);
	return (l^r);
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	init(1,n,1);
	for( int q = 0 , t,x,y ; q < m ; q++ ) {
		scanf("%d%d%d",&t,&x,&y);
		if(t == 1)
			update(1,n,x,y,1);
		else
			printf("%d\n",query(1,n,x,y,1));
	}
	return 0;
}
