#include <bits/stdc++.h>
#define maxn 200003
using namespace std;
typedef long long LL;

LL ans;
int n,q;
int tree[2][4*maxn];

void init(int x , int y , int id) {
	tree[0][id] = tree[1][id] = n;
	if(x == y)
		return;
	int mid = (x+y) >> 1;
	init(x,mid,id*2);
	init(mid+1,y,id*2+1);
}

int query(int cx , int cy , int q , int t , int id) {
	if(cy < q || q < cx)
		return maxn;
	if(cx == cy)
		return tree[t][id];
	int mid = (cx+cy) >> 1;
	int l = query(cx,mid,q,t,id*2);
	int r = query(mid+1,cy,q,t,id*2+1);
	int res = min(l,r);
	return min(res,tree[t][id]);
}

void update(int cx , int cy , int qx , int qy , int val , int t , int id) {
	if(cy < qx || qy < cx)
		return;
	if(qx <= cx && cy <= qy) {
		tree[t][id] = min(tree[t][id],val);
		return;
	}
	int mid = (cx+cy)>>1;
	update(cx,mid,qx,qy,val,t,id*2);
	update(mid+1,cy,qx,qy,val,t,id*2+1);
}

int main() {
	scanf("%d%d",&n,&q);
	ans = (LL)(n-2)*(n-2);
	init(1,n,1);
	for( int qq = 0 , t,x ; qq < q ; qq++ ) {
		scanf("%d%d",&t,&x);
		t--;
		if(x == 1)
			continue;
		int sq = query(1,n,x,t,1);
		if(sq > 2) {
			ans -= sq-2;
			update(1,n,2,sq-1,x,1-t,1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
