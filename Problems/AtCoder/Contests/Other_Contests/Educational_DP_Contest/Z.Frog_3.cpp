#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200000
#define maxh 1000001
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,LL> piLL;

LL c;
int n;
int h[maxn];
LL dp[maxn];
vector<piLL> tree;

void init() {
	tree.resize(4*maxh, piLL(0, LLONG_MAX));
}

LL calcCost(int pos, piLL func) {
	return (LL) func.fi * pos + func.se;
}

LL query(int tx, int ty, int q, int id) {
	LL currCost = calcCost(q, tree[id]);
	if(ty == tx+1)
		return currCost;
	int mid = (tx + ty) >> 1;
	LL childCost;
	if(q < mid)
		childCost = query(tx, mid, q, id*2);
	else
		childCost = query(mid, ty, q, id*2+1);
	return min(currCost, childCost);
}

void update(int tx, int ty, piLL p, int id) {
	int mid = (tx + ty) >> 1;
	bool leftSmaller = calcCost(tx, p) < calcCost(tx, tree[id]);
	bool midSmaller = calcCost(mid, p) < calcCost(mid, tree[id]);
	if(midSmaller)
		swap(tree[id], p);
	if(ty == tx+1)
		return;
	if(leftSmaller != midSmaller)
		update(tx, mid, p, id*2);
	else
		update(mid, ty, p, id*2+1);
}

int main() {
	init();
	scanf("%d%lld",&n,&c);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&h[i]);
	for( int i = 0 ; i < n ; i++ ) {
		if(i)
			dp[i] = query(1, maxh, h[i], 1) + (LL) h[i]*h[i] + c;
		piLL p = piLL(-2*h[i], dp[i] + (LL) h[i]*h[i]);
		update(1, maxh, p, 1);
	}
	printf("%lld\n",dp[n-1]);
	return 0;
}
