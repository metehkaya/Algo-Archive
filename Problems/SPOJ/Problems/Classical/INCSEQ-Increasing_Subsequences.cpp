#include <bits/stdc++.h>
#define maxk 51
#define maxn 10003
#define mod 5000000
using namespace std;

struct pack {
	int val,id,ord;
}ar[maxn];

bool comp1(const pack& a , const pack& b) {
	return a.val < b.val;
}

bool comp2(const pack& a , const pack& b) {
	return a.id < b.id;
}

int n,m,k;
int tree[maxk][4*maxn];

int query(int cx , int cy , int qx , int qy , int t , int id) {
	if(qy < cx || cy < qx)
		return 0;
	if(qx <= cx && cy <= qy)
		return tree[t][id];
	int mid = (cx+cy) >> 1;
	int l = query(cx,mid,qx,qy,t,2*id);
	int r = query(mid+1,cy,qx,qy,t,2*id+1);
	return (l+r) % mod;
}

void update(int cx , int cy , int q , int val , int t , int id) {
	if(cy < q || q < cx)
		return;
	tree[t][id] = (tree[t][id] + val) % mod;
	if(cx == cy)
		return;
	int mid = (cx+cy) >> 1;
	update(cx,mid,q,val,t,2*id);
	update(mid+1,cy,q,val,t,2*id+1);
}

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i].val);
		ar[i].id = i;
	}
	sort(ar+1,ar+n+1,comp1);
	for( int i = 1 , j = 1 ; i <= n ; i = j ) {
		m++;
		while(j <= n && ar[i].val == ar[j].val)
			ar[j++].ord = m;
	}
	sort(ar+1,ar+n+1,comp2);
	for( int i = 1 ; i <= n ; i++ ) {
		for( int j = k ; j > 1 ; j-- ) {
			int val = query(1,m,1,ar[i].ord-1,j-1,1);
			update(1,m,ar[i].ord,val,j,1);
		}
		update(1,m,ar[i].ord,1,1,1);
	}
	printf("%d\n",tree[k][1]);
	return 0;
}
