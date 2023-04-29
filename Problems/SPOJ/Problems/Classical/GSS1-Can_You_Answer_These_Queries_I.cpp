#include <bits/stdc++.h>
#define maxn 50001
using namespace std;

struct pack {
	int res,sum,pre,suf;
} tree[4*maxn];

pack getPack(int x) {
	pack p;
	p.res = p.sum = p.pre = p.suf = x;
	return p;
}

int n,m;
int ar[maxn];

pack merge(pack l , pack r) {
	pack p;
	p.sum = l.sum + r.sum;
	p.res = max( max(l.res,r.res) , l.suf+r.pre );
	p.pre = max( l.pre , l.sum + r.pre );
	p.suf = max( r.suf , r.sum + l.suf );
	return p;
}

pack query(int cx , int cy , int qx , int qy , int id) {
	if(qy < cx || cy < qx)
		return getPack(INT_MIN);
	if(qx <= cx && cy <= qy)
		return tree[id];
	int mid = (cx+cy) >> 1;
	pack l = query(cx,mid,qx,qy,2*id);
	pack r = query(mid+1,cy,qx,qy,2*id+1);
	pack p;
	if(l.res == INT_MIN)
		p = r;
	else if(r.res == INT_MIN)
		p = l;
	else
		p = merge(l,r);
	return p;
}

pack init(int x , int y , int id) {
	if(x == y)
		return tree[id] = getPack(ar[x]);
	int mid = (x+y) >> 1;
	pack l = init(x,mid,2*id);
	pack r = init(mid+1,y,2*id+1);
	return tree[id] = merge(l,r);
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	init(1,n,1);
	scanf("%d",&m);
	for( int q = 0 , x,y ; q < m ; q++ ) {
		scanf("%d%d",&x,&y);
		pack p = query(1,n,x,y,1);
		printf("%d\n",p.res);
	}
	return 0;
}
