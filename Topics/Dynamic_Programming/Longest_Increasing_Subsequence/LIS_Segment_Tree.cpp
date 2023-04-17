#include <bits/stdc++.h>
#define maxn 100003
using namespace std;

struct st {
	int id,ord,val;
}ar[maxn];

bool compId(const st& a , const st& b) {
	return a.id < b.id;
}

bool compVal(const st& a , const st& b) {
	if(a.val != b.val)
		return a.val < b.val;
	return a.id > b.id;
}

int n,ans;
int tree[4*maxn];

int query(int cx , int cy , int qx , int qy , int id) {
	if(qy < cx || cy < qx)
		return 0;
	if(qx <= cx && cy <= qy)
		return tree[id];
	int mid = (cx+cy) >> 1;
	int l = query(cx,mid,qx,qy,id*2);
	int r = query(mid+1,cy,qx,qy,id*2+1);
	return max(l,r);
}

void update(int cx , int cy , int q , int val , int id) {
	if(cy < q || q < cx)
		return;
	tree[id] = max(tree[id],val);
	if(cx == cy)
		return;
	int mid = (cx+cy) >> 1;
	update(cx,mid,q,val,id*2);
	update(mid+1,cy,q,val,id*2+1);
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		ar[i].id = i;
		scanf("%d",&ar[i].val);
	}
	sort(ar+1,ar+n+1,compVal);
	for( int i = 1 ; i <= n ; i++ )
		ar[i].ord = i;
	sort(ar+1,ar+n+1,compId);
	for( int i = 1 ; i <= n ; i++ ) {
		int k = ar[i].ord;
		int val = query(1,n,1,k-1,1);
		ans = max(ans,++val);
		update(1,n,k,val,1);
	}
	printf("LIS Length: %d\n",ans);
	return 0;
}
