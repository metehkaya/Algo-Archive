#include <bits/stdc++.h>
#define maxs 201
#define maxn 200000
using namespace std;

int n,d,ans;
int ar[maxn];
int tree[4*maxs];

void update(int cx , int cy , int q , int val , int id) {
	if(cy < q || q < cx)
		return;
    tree[id] += val;
	if(cx == cy)
		return;
	int mid = (cx+cy) >> 1;
	update(cx,mid,q,val,id*2);
	update(mid+1,cy,q,val,id*2+1);
}

int query( int cx , int cy , int rem , int id ) {
	if(cx == cy)
		return cx;
	int mid = (cx+cy) >> 1;
	int l = tree[2*id];
	if(l < rem)
		return query(mid+1,cy,rem-l,id*2+1);
	else
		return query(cx,mid,rem,id*2);
}

int main() {
	scanf("%d%d",&n,&d);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 0 ; i < d ; i++ )
		update(0,maxs-1,ar[i],+1,1);
	for( int i = d ; i < n ; i++ ) {
		if(d % 2) {
			int med = query(0,maxs-1,d/2+1,1);
			if(ar[i] >= 2*med)
				ans++;
		}
		else {
			int a = query(0,maxs-1,d/2,1);
			int b = query(0,maxs-1,d/2+1,1);
			if(ar[i] >= a+b)
				ans++;
		}
		update(0,maxs-1,ar[i-d],-1,1);
		update(0,maxs-1,ar[i],+1,1);
	}
	printf("%d\n",ans);
	return 0;
}
