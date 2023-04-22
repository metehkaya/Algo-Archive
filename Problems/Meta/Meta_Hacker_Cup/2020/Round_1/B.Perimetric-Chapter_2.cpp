#include <bits/stdc++.h>
#define maxn 1000001
#define maxm 2000001
#define pb push_back
#define mod 1000000007LL
using namespace std;
typedef long long LL;

int T,n,k,m;
LL ans;
LL al,bl,cl,dl;
LL ah,bh,ch,dh;
LL aw,bw,cw,dw;
LL l[maxn];
LL h[maxn];
LL w[maxn];
LL ar[maxm];
map<LL,int> ids;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	m = 0;
	ans = 1;
	ids.clear();
}

void input() {
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= k ; i++ )
		scanf("%lld",&l[i]);
	scanf("%lld%lld%lld%lld",&al,&bl,&cl,&dl);
	for( int i = 1 ; i <= k ; i++ )
		scanf("%lld",&w[i]);
	scanf("%lld%lld%lld%lld",&aw,&bw,&cw,&dw);
	for( int i = 1 ; i <= k ; i++ )
		scanf("%lld",&h[i]);
	scanf("%lld%lld%lld%lld",&ah,&bh,&ch,&dh);
	for( int i = k+1 ; i <= n ; i++ ) {
		l[i] = al*l[i-2] + bl*l[i-1] + cl;
		l[i] = l[i] % dl + 1;
	}
	for( int i = k+1 ; i <= n ; i++ ) {
		w[i] = aw*w[i-2] + bw*w[i-1] + cw;
		w[i] = w[i] % dw + 1;
	}
	for( int i = k+1 ; i <= n ; i++ ) {
		h[i] = ah*h[i-2] + bh*h[i-1] + ch;
		h[i] = h[i] % dh + 1;
	}
}

void precalc() {
	set<int> xs;
	for( int i = 1 ; i <= n ; i++ ) {
		xs.insert(l[i]);
		xs.insert(l[i]+w[i]);
	}
	set<int>::iterator it;
	for( it = xs.begin() ; it != xs.end() ; it++ ) {
		ids[(*it)] = ++m;
		ar[m] = (*it);
	}
}

void solve() {
	LL sumx = 0 , sumy = 0;
	set<int> idle;
	for( int i = 0 ; i <= m+1 ; i++ )
		idle.insert(i);
	for( int i = 1 ; i <= n ; i++ ) {
		vector<int> v;
		int x = ids[l[i]];
		int y = ids[l[i]+w[i]];
		set<int>::iterator it = idle.lower_bound(x);
		while((*it) < y) {
			v.pb((*it));
			it++;
		}
		int cnt = 0;
		if(v.empty())
			cnt = 1;
		else {
			cnt = 0;
			if(v.front() != x || idle.find(x-1) == idle.end())
				cnt++;
			if(v.back() != y-1 || idle.find(y) == idle.end())
				cnt++;
			int sz = v.size();
			for( int j = 0 ; j < sz ; j++ ) {
				idle.erase(v[j]);
				sumx += ar[v[j]+1] - ar[v[j]];
				if(j)
					if(v[j] != v[j-1]+1)
						cnt++;
			}
		}
		if(cnt == 0)
			sumy += h[i];
		else if(cnt > 1) {
			LL times = cnt-1;
			sumy -= h[i]*times;
		}
		LL curr = 2 * (sumx + sumy);
		curr %= mod;
		ans = (ans * curr) % mod;
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		precalc();
		solve();
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
