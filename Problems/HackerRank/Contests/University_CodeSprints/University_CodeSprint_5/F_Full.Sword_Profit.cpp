#include <bits/stdc++.h>
#define maxd 100001
#define maxn 300005
#define mod 1000000007LL
using namespace std;
typedef long long LL;

const LL BIG_COST = (LL) 1e18;

int n;
LL ans;
LL q[maxn];
LL a[maxn];
LL b[maxn];
LL r[maxn];
LL d[maxn];
int tree[4*maxd];

LL findCost(int ind , int value) {
	if(ind == 0)
		return BIG_COST;
	return (LL)ind*value+r[ind];
}

int goo(int cx , int cy , int myIndex , int treeIndex , int id) {
	if(treeIndex == 0)
		treeIndex = tree[id];
	else if(tree[id] != 0)
		treeIndex = min( treeIndex , tree[id] );
	if(findCost(myIndex,cx) <= findCost(treeIndex,cx))
		return cx;
	if(cx == cy)
		return cy+1;
	int mid = (cx+cy) >> 1;
	int R = goo(mid+1,cy,myIndex,treeIndex,2*id+1);
	if(R == mid+1)
		return goo(cx,mid,myIndex,treeIndex,2*id);
	return R;
}

void update(int cx , int cy , int qx , int qy , int val , int id) {
	if(qy < cx || cy < qx)
		return;
	if(qx <= cx && cy <= qy) {
		tree[id] = val;
		return;
	}
	int mid = (cx+cy) >> 1;
	update(cx,mid,qx,qy,val,id*2);
	update(mid+1,cy,qx,qy,val,id*2+1);
}

int query(int cx , int cy , int q , int id) {
	if(cx == cy)
		return tree[id];
	int mid = (cx+cy) >> 1;
	if(q <= mid) {
		int l = query(cx,mid,q,id*2);
		if(tree[id] == 0)
			return l;
		else if(l == 0)
			return tree[id];
		return min(l,tree[id]);
	}
	else {
		int r = query(mid+1,cy,q,id*2+1);
		if(tree[id] == 0)
			return r;
		else if(r == 0)
			return tree[id];
		return min(r,tree[id]);
	}
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%lld%lld%lld%lld%lld",&q[i],&a[i],&b[i],&r[i],&d[i]);
	for( int i = n ; i >= 1 ; i-- ) {
		int upd = goo(1,maxd-1,i,0,1);
		update(1,maxd-1,upd,maxd-1,i,1);
		int j = query(1,maxd-1,d[i],1);
		if(j == 0)
			continue;
		LL c = d[i];
		LL highProfit = q[i] + i*c - a[i] - b[i] - findCost(j,c);
		if(highProfit > 0) {
			LL cnt = highProfit / b[i];
			if(highProfit%b[i] > 0)
				cnt++;
			LL lowProfit = highProfit - (cnt-1)*b[i];
			LL add;
			if(cnt % 2 == 0) {
				add = (cnt/2) % mod;
				add *= (cnt-1) % mod;
				add %= mod;
			}
			else {
				add = ((cnt-1) / 2) % mod;
				add *= cnt % mod;
				add %= mod;
			}
			add = (add * b[i]) % mod;
			add = (add + ((lowProfit % mod) * (cnt % mod)) % mod) % mod;
			ans = (ans + add) % mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
