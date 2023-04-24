#include <bits/stdc++.h>
#define maxn 100003
typedef long long LL;
using namespace std;

const LL INF = (LL) 1e18;

struct data {
	int h,p,ind,ord;
} ar[maxn];

bool comp1( data a , data b ) {
	return a.h < b.h;
}

bool comp2( data a , data b ) {
	return a.ind < b.ind;
}

int n,K;
int nextbig[maxn];
int leftmost[4*maxn];
LL cost[maxn];
LL tree[4*maxn];

void init2(int x , int y , int pos) {
	tree[pos] = INF;
	if(x == y)
		return;
	int mid = (x+y) >> 1;
	init2(x,mid,pos*2);
	init2(mid+1,y,pos*2+1);
}

void update2(int cx , int cy , int qx , int qy , LL val , int pos) {
	if(cy < qx || qy < cx)
		return;
	if(qx <= cx && cy <= qy) {
		tree[pos] = min(tree[pos],val);
		return;
	}
	int mid = (cx+cy) >> 1;
	update2(cx,mid,qx,qy,val,pos*2);
	update2(mid+1,cy,qx,qy,val,pos*2+1);
}

LL query2(int cx , int cy , int q , int pos) {
	if(cy < q || q < cx)
		return INF;
	if(cx == cy)
		return tree[pos];
	int mid = (cx+cy) >> 1;
	LL q1 = query2(cx,mid,q,pos*2);
	LL q2 = query2(mid+1,cy,q,pos*2+1);
	return min(min(q1,q2),tree[pos]);
}

void init1(int x , int y , int pos) {
	leftmost[pos] = n + 1;
	if(x == y)
		return;
	int mid = (x+y) >> 1;
	init1(x,mid,pos*2);
	init1(mid+1,y,pos*2+1);
}

void update1(int cx , int cy , int q , int val , int pos) {
	if(cy < q || q < cx)
		return;
	leftmost[pos] = val;
	if(cx == cy)
		return;
	int mid = (cx+cy) >> 1;
	update1(cx,mid,q,val,pos*2);
	update1(mid+1,cy,q,val,pos*2+1);
}

int query1(int cx , int cy , int qx , int qy , int pos) {
	if(cy < qx || qy < cx)
		return n + 1;
	if(qx <= cx && cy <= qy)
		return leftmost[pos];
	int mid = (cx+cy) >> 1;
	int q1 = query1(cx,mid,qx,qy,pos*2);
	int q2 = query1(mid+1,cy,qx,qy,pos*2+1);
	return min(q1,q2);
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		ar[i].ind = i;
	ar[1].p = 0;
	scanf("%d",&ar[1].h);
	for( int i = 2 ; i <= n ; i++ )
		scanf("%d",&ar[i].h);
	for( int i = 2 ; i <= n ; i++ )
		scanf("%d",&ar[i].p);
	sort(ar+1,ar+n+1,comp1);
	for( int l = 1 , r = 1 ; l <= n ; l = r ) {
		K++;
		while(r <= n && ar[l].h == ar[r].h)
			ar[r++].ord = K;
	}
	sort(ar+1,ar+n+1,comp2);
	init1(1,K,1);
	for( int i = n ; i >= 1 ; i-- ) {
		nextbig[i] = query1(1,K,ar[i].ord+1,K,1);
		update1(1,K,ar[i].ord,i,1);
	}
	init2(1,n,1);
	ar[1].p = cost[1] = 0;
	for( int i = 2 ; i <= n ; i++ )
		cost[i] = INF;
	for( int i = 1 ; i <= n ; i++ ) {
		cost[i] = min(cost[i],query2(1,n,i,1)-ar[i].h) + ar[i].p;
		if(i+1 != nextbig[i])
			update2(1,n,i+1,nextbig[i]-1,cost[i]+ar[i].h,1);
		if(nextbig[i] != n+1)
			cost[nextbig[i]] = min(cost[nextbig[i]],cost[i]+ar[nextbig[i]].h-ar[i].h);
	}
	LL ans = INF;
	for( int i = 1 ; i <= n ; i++ )
		if(nextbig[i] == n+1)
			ans = min(ans,cost[i]+n);
	cout << ans << endl;
	return 0;
}
