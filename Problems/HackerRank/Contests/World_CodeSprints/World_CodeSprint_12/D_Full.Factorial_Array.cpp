#include <bits/stdc++.h>
#define maxk 40
#define maxn 100001
#define mod 1000000000
using namespace std;
typedef long long LL;

int n,m;
int fact[maxk];
int tree[4*maxn];
int lazy[4*maxn];
int cnt[4*maxn][maxk];

void init(int x , int y , int pos) {
	if(x == y) {
		int val;
		scanf("%d",&val);
		if(val <= 39) {
			cnt[pos][val] = 1;
			tree[pos] = fact[val];
		}
		return;
	}
	int mid = (x+y) >> 1;
	init(x,mid,pos*2);
	init(mid+1,y,pos*2+1);
	tree[pos] = (tree[pos*2] + tree[pos*2+1]) % mod;
	for( int i = 1 ; i <= 39 ; i++ )
		cnt[pos][i] = cnt[pos*2][i] + cnt[pos*2+1][i];
}

void upd2(int cx , int cy , int q , int val , int pos) {
	if(lazy[pos]) {
		for( int i = 39 ; i - lazy[pos] >= 1 ; i-- )
			cnt[pos][i] = cnt[pos][i-lazy[pos]];
		for( int i = 1 ; i <= min( lazy[pos] , 39 ) ; i++ )
			cnt[pos][i] = 0;
		tree[pos] = 0;
		for( int i = 1 ; i <= 39 ; i++ )
			tree[pos] = ( tree[pos] + ( (LL) fact[i] * cnt[pos][i] ) % mod ) % mod;
		if( cx < cy ) {
			lazy[pos*2] += lazy[pos];
			lazy[pos*2+1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(q < cx || cy < q)
		return;
	if(cx == cy) {
		memset(cnt[pos],0,sizeof(cnt[pos]));
		if(val <= 39) {
			cnt[pos][val] = 1;
			tree[pos] = fact[val];
		}
		else
			tree[pos] = 0;
		return;
	}
	int mid = (cx + cy) >> 1;
	upd2(cx,mid,q,val,pos*2);
	upd2(mid+1,cy,q,val,pos*2+1);
	tree[pos] = (tree[pos*2] + tree[pos*2+1]) % mod;
	for( int i = 1 ; i <= 39 ; i++ )
		cnt[pos][i] = cnt[pos*2][i] + cnt[pos*2+1][i];
}

void upd(int cx , int cy , int qx , int qy , int pos) {
	if(lazy[pos]) {
		for( int i = 39 ; i - lazy[pos] >= 1 ; i-- )
			cnt[pos][i] = cnt[pos][i-lazy[pos]];
		for( int i = 1 ; i <= min(lazy[pos],39) ; i++ )
			cnt[pos][i] = 0;
		tree[pos] = 0;
		for( int i = 1 ; i <= 39 ; i++ )
			tree[pos] = ( tree[pos] + ( (LL) fact[i] * cnt[pos][i] ) % mod ) % mod;
		if(cx < cy) {
			lazy[pos*2] += lazy[pos];
			lazy[pos*2+1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(qy < cx || cy < qx)
		return;
	if(qx <= cx && cy <= qy) {
		for( int i = 39 ; i >= 2 ; i-- )
			cnt[pos][i] = cnt[pos][i-1];
		cnt[pos][1] = 0;
		tree[pos] = 0;
		for( int i = 1 ; i <= 39 ; i++ )
			tree[pos] = ( tree[pos] + ( (LL) fact[i] * cnt[pos][i] ) % mod ) % mod;
		if(cx < cy) {
			lazy[pos*2] += 1;
			lazy[pos*2+1] += 1;
		}
		return;
	}
	int mid = (cx+cy) >> 1;
	upd(cx,mid,qx,qy,pos*2);
	upd(mid+1,cy,qx,qy,pos*2+1);
	tree[pos] = (tree[pos*2] + tree[pos*2+1]) % mod;
	for( int i = 1 ; i <= 39 ; i++ )
		cnt[pos][i] = cnt[pos*2][i] + cnt[pos*2+1][i];
}

int query(int cx , int cy , int qx , int qy , int pos) {
	if(lazy[pos]) {
		for( int i = 39 ; i - lazy[pos] >= 1 ; i-- )
			cnt[pos][i] = cnt[pos][i-lazy[pos]];
		for( int i = 1 ; i <= min(lazy[pos],39) ; i++ )
			cnt[pos][i] = 0;
		tree[pos] = 0;
		for( int i = 1 ; i <= 39 ; i++ )
			tree[pos] = ( tree[pos] + ( (LL) fact[i] * cnt[pos][i] ) % mod ) % mod;
		if(cx < cy) {
			lazy[pos*2] += lazy[pos];
			lazy[pos*2+1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(qy < cx || cy < qx)
		return 0;
	if(qx <= cx && cy <= qy)
		return tree[pos];
	int mid = (cx+cy) >> 1;
	return ( query(cx,mid,qx,qy,pos*2) + query(mid+1,cy,qx,qy,pos*2+1) ) % mod;
}

int main() {
	fact[0] = 1;
	for( int i = 1 ; i < maxk ; i++ )
		fact[i] = ((LL)i*fact[i-1]) % mod;
	scanf("%d%d",&n,&m);
	init(1,n,1);
	for( int i = 0 , t,x,y ; i < m ; i++ ) {
		scanf("%d%d%d",&t,&x,&y);
		if(t == 1)
			upd(1,n,x,y,1);
		else if(t == 2)
			printf("%d\n",query(1,n,x,y,1));
		else
			upd2(1,n,x,y,1);
	}
	return 0;
}
