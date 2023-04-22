#include <bits/stdc++.h>
#define pb push_back
#define mod 1000000007
using namespace std;
typedef long long LL;

int T,n,m;
LL ans;
vector<LL> treex,treey;
vector<LL> wellx,welly;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	ans = 0;
	treex.clear();
	treey.clear();
	wellx.clear();
	welly.clear();
}

void input() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		LL x,y;
		scanf("%lld%lld",&x,&y);
		treex.pb(x);
		treey.pb(y);
	}
	scanf("%d",&m);
	for( int i = 0 ; i < m ; i++ ) {
		LL x,y;
		scanf("%lld%lld",&x,&y);
		wellx.pb(x);
		welly.pb(y);
	}
}

void solve(vector<LL>& tree , vector<LL>& well) {
	LL sum1 = 0 , sum2 = 0;
	for( int i = 0 ; i < n ; i++ ) {
		LL t = tree[i];
		sum1 = (sum1 + t) % mod;
		sum2 = (sum2 + (t*t)%mod) % mod;
	}
	for( int i = 0 ; i < m ; i++ ) {
		LL w = well[i];
		LL w2 = (w*w) % mod;
		ans = (ans + sum2) % mod;
		ans = (ans + (n*w2)%mod) % mod;
		LL neg = (2*w*sum1) % mod;
		ans = (ans - neg + mod) % mod;
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve(treex,wellx);
		solve(treey,welly);
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
