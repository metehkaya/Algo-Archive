#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 2501
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int n;
LL ans=1;
pi ar[maxn];
int tree[maxn];
vector<int> xs,ys;
map<int,int> mpx,mpy;

int query(int x) {
	int sum = 0;
	while(x) {
		sum += tree[x];
		x -= (x & (-x));
	}
	return sum;
}

void update(int x) {
	while(x <= n) {
		tree[x]++;
		x += (x & (-x));
	}
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d%d",&ar[i].fi,&ar[i].se);
		xs.pb(ar[i].fi);
		ys.pb(ar[i].se);
	}
	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());
	for( int i = 0 ; i < n ; i++ ) {
		mpx[xs[i]] = i+1;
		mpy[ys[i]] = i+1;
	}
	for( int i = 1 ; i <= n ; i++ ) {
		ar[i].fi = mpx[ar[i].fi];
		ar[i].se = mpy[ar[i].se];
	}
	sort(ar+1,ar+n+1);
	for( int i = 1 ; i <= n ; i++ ) {
		ans++;
		memset(tree,0,sizeof(tree));
		update(ar[i].se);
		for( int j = i-1 ; j >= 1 ; j-- ) {
			update(ar[j].se);
			int mn = min(ar[i].se,ar[j].se);
			int mx = max(ar[i].se,ar[j].se);
			int lower = query(mn-1) + 1;
			int upper = (i-j+1) - query(mx) + 1;
			ans += (LL) lower * upper;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
