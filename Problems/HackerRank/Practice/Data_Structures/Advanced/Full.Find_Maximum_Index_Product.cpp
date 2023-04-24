#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

struct data {
	int val;
	int pos;
	int ord;
} ar[maxn];

bool comp1(data a , data b) {
	return a.val < b.val;
}

bool comp2(data a , data b) {
	return a.pos < b.pos;
}

LL ans;
int n,k;
int l[maxn];
int r[maxn];
int tree[4*maxn];

void read() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i].val);
		ar[i].pos = i;
	}
}

void preCalc() {
	sort(ar+1,ar+n+1,comp1);
	for( int l = 1 , r = 1 ; l <= n ; l = r ) {
		k++;
		while(r <= n && ar[l].val == ar[r].val)
			ar[r++].ord = k;
	}
	sort(ar+1,ar+n+1,comp2);
}

void update(int cx , int cy , int q , int val , int id) {
	if(cy < q || q < cx)
		return;
	tree[id] = max(tree[id],val);
	if(cx == cy)
		return;
	int mid = (cx + cy) >> 1;
	update(cx,mid,q,val,id*2);
	update(mid+1,cy,q,val,id*2+1);
}

int query(int cx , int cy , int qx , int qy , int id) {
	if(cy < qx || qy < cx)
		return 0;
	if(qx <= cx && cy <= qy)
		return tree[id];
	int mid = (cx + cy) >> 1;
	int L = query(cx,mid,qx,qy,id*2);
	int R = query(mid+1,cy,qx,qy,id*2+1);
	return max(L,R);
}

void solve() {
	for( int i = 1 ; i <= n ; i++ ) {
		l[i] = query(1,k,ar[i].ord+1,k,1);
		update(1,k,ar[i].ord,i,1);
	}
	memset(tree,0,sizeof(tree));
	for( int i = n ; i >= 1 ; i-- ) {
		r[i] = n + 1 - query(1,k,ar[i].ord+1,k,1);
		update(1,k,ar[i].ord,n+1-i,1);
	}
	for( int i = 1 ; i <= n ; i++ ) {
		if(r[i] == n + 1)
			r[i] = 0;
		ans = max(ans,(LL)l[i]*r[i]);
	}
	printf("%lld\n",ans);
}

int main() {
	read();
	preCalc();
	solve();
	return 0;
}
