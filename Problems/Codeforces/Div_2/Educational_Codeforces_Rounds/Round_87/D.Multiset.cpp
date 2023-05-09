#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;

int n,m,ans;
int tree[4*maxn];

void update(int cx , int cy , int q , int add , int id) {
	if(cy < q || q < cx)
		return;
	tree[id] += add;
	if(cx == cy)
		return;
	int mid = (cx+cy) >> 1;
	update(cx,mid,q,add,id*2);
	update(mid+1,cy,q,add,id*2+1);
}

int query(int cx , int cy , int& k , int id) {
	if(tree[id] < k) {
		k -= tree[id];
		return -1;
	}
	if(cx == cy)
		return cx;
	int mid = (cx+cy) >> 1;
	int res = query(cx,mid,k,id*2);
	if(res != -1)
		return res;
	return query(mid+1,cy,k,id*2+1);
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x ; i < n+m ; i++ ) {
		scanf("%d",&x);
		if(x > 0)
			update(1,n,x,+1,1);
		else {
			x = -x;
			int k = query(1,n,x,1);
			update(1,n,k,-1,1);
		}
	}
	int first = 1;
	ans = max( query(1,n,first,1) , 0 );
	printf("%d\n",ans);
	return 0;
}
