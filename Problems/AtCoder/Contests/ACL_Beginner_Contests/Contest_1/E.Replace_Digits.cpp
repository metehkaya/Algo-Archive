#include <bits/stdc++.h>
#define maxn 200005
#define mod 998244353
using namespace std;
typedef long long LL;

int n,m;
LL pw[maxn];
LL sum[maxn];
int tree[4*maxn];
int lazy[4*maxn];

int proc(int x , int y , int val) {
	int l = n-y;
	int r = n-x;
	LL res = sum[r];
	if(l)
		res = (res - sum[l-1] + mod) % mod;
	res = (res * val) % mod;
	return res;
}

void init(int x , int y , int id) {
	tree[id] = proc(x,y,1);
	if(x == y)
		return;
	int mid = (x+y) >> 1;
	init(x,mid,id*2);
	init(mid+1,y,id*2+1);
}

int update(int cx , int cy , int qx , int qy , int val , int id) {
	if(lazy[id]) {
		tree[id] = proc(cx,cy,lazy[id]);
		if(cx != cy)
			lazy[id*2] = lazy[id*2+1] = lazy[id];
		lazy[id] = 0;
	}
	if(qy < cx || cy < qx)
		return tree[id];
	if(qx <= cx && cy <= qy) {
		tree[id] = proc(cx,cy,val);
		if(cx != cy)
			lazy[id*2] = lazy[id*2+1] = val;
		return tree[id];
	}
	int mid = (cx + cy) >> 1;
	int l = update(cx,mid,qx,qy,val,id*2);
	int r = update(mid+1,cy,qx,qy,val,id*2+1);
	return tree[id] = (l+r) % mod;
}

int main() {
	pw[0] = 1;
	for( int i = 1 ; i < maxn ; i++ )
		pw[i] = (pw[i-1] * 10LL) % mod;
	sum[0] = 1;
	for( int i = 1 ; i < maxn ; i++ )
		sum[i] = (sum[i-1] + pw[i]) % mod;
	scanf("%d%d",&n,&m);
	init(1,n,1);
	for( int i = 0 , x,y,v ; i < m ; i++ ) {
		scanf("%d%d%d",&x,&y,&v);
		printf("%d\n",update(1,n,x,y,v,1));
	}
	return 0;
}
