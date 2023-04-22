#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;
typedef long long LL;

int T,n,m,k,s;
LL ans;
LL p[maxn];
LL q[maxn];
LL ap,bp,cp,dp;
LL aq,bq,cq,dq;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void input() {
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for( int i = 1 ; i <= k ; i++ )
		scanf("%lld",&p[i]);
	scanf("%lld%lld%lld%lld",&ap,&bp,&cp,&dp);
	for( int i = 1 ; i <= k ; i++ )
		scanf("%lld",&q[i]);
	scanf("%lld%lld%lld%lld",&aq,&bq,&cq,&dq);
	for( int i = k+1 ; i <= n ; i++ ) {
		p[i] = ap*p[i-2] + bp*p[i-1] + cp;
		p[i] = p[i] % dp + 1;
	}
	for( int i = k+1 ; i <= m ; i++ ) {
		q[i] = aq*q[i-2] + bq*q[i-1] + cq;
		q[i] = q[i] % dq + 1;
	}
}

bool f(LL a , LL b , LL c , LL t) {
	LL req;
	bool left1 = (b < a);
	bool left2 = (c < a);
	if(left1 && left2)
		req = a-b;
	else if(!left1 && !left2)
		req = c-a;
	else
		req = c-b + min(c-a,a-b);
	return req <= t;
}

bool check(LL t) {
	int idx = 1;
	for( int i = 1 ; i <= n && idx <= m ; i++ ) {
		int idx2 = idx;
		while(idx2 <= m && f(p[i],q[idx],q[idx2],t))
			idx2++;
		idx = idx2;
	}
	return idx > m;
}

void solve() {
	sort(p+1,p+n+1);
	sort(q+1,q+m+1);
	LL l = 0 , r = (1LL << 40);
	while(l <= r) {
		LL mid = (l+r) >> 1;
		if(check(mid))
			ans = mid , r = mid-1;
		else
			l = mid+1;
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		input();
		solve();
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
