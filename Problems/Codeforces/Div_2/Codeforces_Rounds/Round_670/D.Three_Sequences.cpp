#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

LL inc;
int n,m;
int ar[maxn];
LL tree[4*maxn];

LL query(int cx , int cy , int q , int id) {
	if(cy < q || q < cx)
		return 0;
	if(cx == cy)
		return tree[id];
	int mid = (cx+cy) >> 1;
	LL res = tree[id];
	res += query(cx,mid,q,id*2);
	res += query(mid+1,cy,q,id*2+1);
	return res;
}

void update(int cx , int cy , int qx , int qy , LL add , int id) {
	if(qy < cx || cy < qx)
		return;
	if(qx <= cx && cy <= qy) {
		tree[id] += add;
		return;
	}
	int mid = (cx+cy) >> 1;
	update(cx,mid,qx,qy,add,id*2);
	update(mid+1,cy,qx,qy,add,id*2+1);
}

void sol() {
	LL X = query(1,n,1,1);
	LL temp = X-inc;
	if(temp%2)
		temp++;
	LL a = temp/2;
	LL b = a+inc;
	printf("%lld\n",b);
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		update(1,n,i,i,ar[i],1);
		if(i > 1 && ar[i] > ar[i-1])
			inc += ar[i]-ar[i-1];
	}
	sol();
	scanf("%d",&m);
	for( int q = 0 , i,j,x ; q < m ; q++ ) {
		scanf("%d%d%d",&i,&j,&x);
		LL oldi = query(1,n,i,1);
		LL oldj = query(1,n,j,1);
		LL newi = oldi+x;
		LL newj = oldj+x;
		update(1,n,i,j,x,1);
		if(i > 1) {
			LL tmp = query(1,n,i-1,1);
			inc -= max(oldi-tmp,0LL);
			inc += max(newi-tmp,0LL);
		}
		if(j < n) {
			LL tmp = query(1,n,j+1,1);
			inc -= max(tmp-oldj,0LL);
			inc += max(tmp-newj,0LL);
		}
		sol();
	}
	return 0;
}
