#include <bits/stdc++.h>
#define maxn 300005
using namespace std;

int n,k,ans;
int tree[4*maxn];

void update(int cx , int cy , int q , int val , int id) {
	if(cy < q || q < cx)
		return;
	tree[id] = max( tree[id] , val );
	if(cx == cy)
		return;
	int mid = (cx+cy) >> 1;
	update(cx,mid,q,val,id*2);
	update(mid+1,cy,q,val,id*2+1);
}

int query(int cx , int cy , int qx , int qy , int id) {
	if(qy < cx || cy < qx)
		return 0;
	if(qx <= cx && cy <= qy)
		return tree[id];
	int mid = (cx+cy) >> 1;
	return max( query(cx,mid,qx,qy,id*2) , query(mid+1,cy,qx,qy,id*2+1) );
}

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 1 , x ; i <= n ; i++ ) {
		scanf("%d",&x);
		int a = max(x-k,0);
		int b = min(x+k,maxn-5);
		int val = query(0,maxn-5,a,b,1) + 1;
		update(0,maxn-5,x,val,1);
		ans = max(ans,val);
	}
	printf("%d\n",ans);
	return 0;
}
