#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

struct data {
	int id,root;
	LL len;
};

bool operator<(data a , data b) {
	if(a.len != b.len)
		return a.len < b.len;
	return a.id < b.id;
}

bool isEqual(data a , data b) {
	if(a.id != b.id)
		return false;
	if(a.root != b.root)
		return false;
	if(a.len != b.len)
		return false;
	return true;
}

data getData(int _id , int _root , LL _len) {
	data d;
	d.id = _id;
	d.root = _root;
	d.len = _len;
	return d;
}

data getBestData(data L , data R) {
	if(L.len > R.len)
		return L;
	if(L.len < R.len)
		return R;
	if(L.id > R.id)
		return L;
	return R;
}

int N,n,m;
int w[maxn];
LL sw[2*maxn];
data tree[8*maxn];
priority_queue<data> queues[2*maxn];

void read() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&w[i]);
}

data init(int x , int y , int pos) {
	if(x == y)
		return tree[pos] = getData(x,x,sw[x-1]);
	int mid = (x+y) >> 1;
	data L = init(x,mid,pos*2);
	data R = init(mid+1,y,pos*2+1);
	return tree[pos] = getBestData(L,R);
}

data update(int cx , int cy , int q , data upd , int pos) {
	if(q < cx || cy < q)
		return tree[pos];
	if(cx == cy)
		return tree[pos] = upd;
	int mid = (cx+cy) >> 1;
	data L = update(cx,mid,q,upd,pos*2);
	data R = update(mid+1,cy,q,upd,pos*2+1);
	return tree[pos] = getBestData(L,R);
}

data query(int cx , int cy , int qx , int qy , int pos) {
	if(cy < qx || qy < cx)
		return getData(0,0,0);
	if(qx <= cx && cy <= qy)
		return tree[pos];
	int mid = (cx+cy) >> 1;
	data L = query(cx,mid,qx,qy,pos*2);
	data R = query(mid+1,cy,qx,qy,pos*2+1);
	return getBestData(L,R);
}

void preSolve() {
	for( int i = 1 ; i <= n ; i++ )
		sw[i] = sw[i-1] + w[i];
	for( int i = n+1 ; i <= 2*n ; i++ )
		sw[i] = sw[i-1] + w[i-n];
	init(1,2*n,1);
	for( int i = 1 ; i <= 2*n ; i++ )
		queues[i].push(getData(i,i,sw[i-1]));
	N = 2*n;
}

void query1() {
	int x,w;
	scanf("%d%d",&x,&w);
	N++;
	data best = query(1,2*n,x,x+n-1,1);
	int id = best.id;
	int root = best.root;
	LL len = best.len;
	LL diff = len - sw[root-1];
	if(root > n)
		root -= n;
	data d1 = getData(N,root,diff+sw[root-1]+w);
	data d2 = getData(N,root+n,diff+sw[root+n-1]+w);
	queues[root].push(d1);
	queues[root+n].push(d2);
	update(1,2*n,root,d1,1);
	update(1,2*n,root+n,d2,1);
}

void query2() {
	int x,w;
	scanf("%d%d",&x,&w);
	N++;
	data d1 = getData(N,x,sw[x-1]+w);
	data d2 = getData(N,x+n,sw[x+n-1]+w);
	queues[x].push(d1);
	queues[x+n].push(d2);
	data best1 = queues[x].top();
	data best2 = queues[x+n].top();
	if(isEqual(best1,d1))
		update(1,2*n,x,d1,1);
	if(isEqual(best2,d2))
		update(1,2*n,x+n,d2,1);
}

void query3() {
	int x;
	scanf("%d",&x);
	data best = query(1,2*n,x,x+n-1,1);
	int root = best.root;
	if(root > n)
		root -= n;
	queues[root].pop();
	data d1 = queues[root].top();
	update(1,2*n,root,d1,1);
	queues[root+n].pop();
	data d2 = queues[root+n].top();
	update(1,2*n,root+n,d2,1);
}

void query4() {
	int x;
	scanf("%d",&x);
	data best = query(1,2*n,x,x+n-1,1);
	printf("%lld\n",best.len-sw[x-1]);
}

void solve() {
	scanf("%d",&m);
	for( int tc = 0 , q ; tc < m ; tc++ ) {
		scanf("%d",&q);
		if(q == 1)
			query1();
		else if(q == 2)
			query2();
		else if(q == 3)
			query3();
		else
			query4();
	}
}

int main() {
	read();
	preSolve();
	solve();
	return 0;
}
