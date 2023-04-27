#include <bits/stdc++.h>
#define maxn 500003
using namespace std;
typedef long long LL;

struct poi {
	int t,l,p;
}ar[maxn];

bool comp(const poi& a , const poi& b) {
	if(a.t != b.t)
		return a.t < b.t;
	return a.l < b.l;
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

void single(int i) {
	LL x = query(1,m,1,mp[ar[i].l],0,1);
	LL y = query(1,m,mp[ar[i].l],m,1,1);
	if(x != LLONG_MIN)
		x = x - d*ar[i].l + ar[i].p;
	if(y != LLONG_MIN)
		y = y + u*ar[i].l + ar[i].p;
	LL val = max(x,y);
	update(1,m,mp[ar[i].l],val+d*ar[i].l,0,1);
	update(1,m,mp[ar[i].l],val-u*ar[i].l,1,1);
	if(ar[i].l < s)
		ans = max(ans,val-d*(s-ar[i].l));
	else
		ans = max(ans,val-u*(ar[i].l-s));
}

void multi(int l , int r) {
	LL dp[r-l];
	LL dpBest1[r-l];
	LL dpBest2[r-l];
	for( int i = l ; i < r ; i++ ) {
		LL x = query(1,m,1,mp[ar[i].l],0,1);
		LL y = query(1,m,mp[ar[i].l],m,1,1);
		if(x != LLONG_MIN)
			x = x - d*ar[i].l + ar[i].p;
		if(y != LLONG_MIN)
			y = y + u*ar[i].l + ar[i].p;
		dp[i-l] = max(x,y);
		dpBest1[i-l] = dpBest2[i-l] = dp[i-l];
	}
	for( int i = l+1 ; i < r ; i++ )
		dpBest1[i-l] = max(dpBest1[i-l],dpBest1[i-1-l]-d*(ar[i].l-ar[i-1].l)+ar[i].p);
	for( int i = r-2 ; i >= l ; i-- )
		dpBest2[i-l] = max(dpBest2[i-l],dpBest2[i+1-l]-u*(ar[i+1].l-ar[i].l)+ar[i].p);
	for( int i = l ; i < r ; i++ ) {
		LL val = max(dpBest1[i-l],dpBest2[i-l]);
		update(1,m,mp[ar[i].l],val+d*ar[i].l,0,1);
		update(1,m,mp[ar[i].l],val-u*ar[i].l,1,1);
		if(ar[i].l < s)
			ans = max(ans,val-d*(s-ar[i].l));
		else
			ans = max(ans,val-u*(ar[i].l-s));
	}
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
	for( int l = 1 , r = 1 ; l <= n ; l = r ) {
		while(r <= n && ar[l].t == ar[r].t)
			r++;
		if(r == l+1)
			single(l);
		else
			multi(l,r);
	}
	printf("%lld\n",ans);
	return 0;
}
