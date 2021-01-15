#include <bits/stdc++.h>
#define maxn 500003
using namespace std;
typedef long long LL;

struct poi {
	int t,l,p;
}ar[maxn];

bool comp(const poi& a , const poi& b) {
	return a.t < b.t;
}

LL ans;
int n,u,d,s,m;
LL tree[4*maxn][2];
map<int,int> mp;

void init(int x , int y , int id) {
	tree[id][0] = LLONG_MIN;
	tree[id][1] = LLONG_MIN;
	if(x == y)
		return;
	int mid = (x+y) >> 1;
	init(x,mid,2*id);
	init(mid+1,y,2*id+1);
}

LL update(int cx , int cy , int q , LL val , int t , int id) {
	if(q < cx || cy < q)
		return tree[id][t];
	tree[id][t] = max(tree[id][t],val);
	if(cx == cy)
		return tree[id][t];
	int mid = (cx+cy) >> 1;
	LL l = update(cx,mid,q,val,t,2*id);
	LL r = update(mid+1,cy,q,val,t,2*id+1);
	return tree[id][t] = max(l,r);
}

LL query(int cx , int cy , int qx , int qy , int t , int id) {
	if(qy < cx || cy < qx)
		return LLONG_MIN;
	if(qx <= cx && cy <= qy)
		return tree[id][t];
	int mid = (cx+cy) >> 1;
	LL l = query(cx,mid,qx,qy,t,2*id);
	LL r = query(mid+1,cy,qx,qy,t,2*id+1);
	return max(l,r);
}

int main() {
	scanf("%d%d%d%d",&n,&u,&d,&s);
	mp[s] = -1;
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d%d%d",&ar[i].t,&ar[i].l,&ar[i].p);
		mp[ar[i].l] = -1;
	}
	map<int,int>::iterator mit;
	for( mit = mp.begin() ; mit != mp.end() ; mit++ )
		mit->second = ++m;
	sort(ar+1,ar+n+1,comp);
	init(1,m,1);
	update(1,m,mp[s],d*s,0,1);
	update(1,m,mp[s],-u*s,1,1);
	for( int i = 1 ; i <= n ; i++ ) {
		LL x = query(1,m,1,mp[ar[i].l],0,1);
		LL y = query(1,m,mp[ar[i].l],m,1,1);
		if(x != LLONG_MIN)
			x = x - d*ar[i].l + ar[i].p;
		if(y != LLONG_MIN)
			y = y + u*ar[i].l + ar[i].p;
		LL val = max(x,y);
		// printf("%d %d %d -> %lld %lld\n",ar[i].t,ar[i].l,ar[i].p,x,y);
		if(val != LLONG_MIN) {
			update(1,m,mp[ar[i].l],val+d*ar[i].l,0,1);
			update(1,m,mp[ar[i].l],val-u*ar[i].l,1,1);
			if(ar[i].l < s)
				ans = max(ans,val-d*(s-ar[i].l));
			else
				ans = max(ans,val-u*(ar[i].l-s));
		}
	}
	printf("%lld\n",ans);
	return 0;
}
