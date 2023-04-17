#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

int n,m;
int ar[maxn];
LL tree[maxn];

LL query(int id) {
	LL res = 0;
	while(id) {
		res += tree[id];
		id -= (id & (-id));
	}
	return res;
}

void update(int id , int val) {
	while(id <= n) {
		tree[id] += val;
		id += (id & (-id));
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		update(i,ar[i]);
	}
	for( int i = 0 , t,x,y,val ; i < m ; i++ ) {
		scanf("%d",&t);
		if(t == 0) {
			scanf("%d%d",&x,&val);
			update(x,val-ar[x]);
			ar[x] = val;
		}
		else {
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(y)-query(x-1));
		}
	}
	return 0;
}
