#include <bits/stdc++.h>
#define fi first
#define se second
#define maxr 321
#define maxs 100001
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

LL ans;
bool center;
int T,tc,n,m,p;
int xps,xms,yps,yms;

int varxp[maxs];
int varxm[maxs];
int varyp[maxs];
int varym[maxs];
bool notPrime[maxr];

vector<int> primes;
vector<int> xp,xm,yp,ym;
vector<pi> tri[maxs];

void input() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		if(x>0)
			xp.pb(x), varxp[x]=tc;
		else if(x==0)
			center = true;
		else
			xm.pb(x), varxm[-x]=tc;
	}
	for( int i = 0 , y ; i < m ; i++ ) {
		scanf("%d",&y);
		if(y>0)
			yp.pb(y), varyp[y]=tc;
		else if(y==0)
			center = true;
		else
			ym.pb(y), varym[-y]=tc;
	}
	n = ( xps = xp.size() ) + ( xms = xm.size() );
	m = ( yps = yp.size() ) + ( yms = ym.size() );
}

void reset() {
	ans = 0;
	center = false;
	xp.clear();
	xm.clear();
	yp.clear();
	ym.clear();
}

void precalc() {
	int sum = 0;
	for( int i = 2 ; i < maxr ; i++ )
		if(!notPrime[i]) {
			primes.pb(i);
			for( int j = i*i ; j < maxr ; j += i )
				notPrime[j] = true;
		}
	p = primes.size();
	for( int i = 1 ; i < maxs ; i++ ) {
		int other = 1;
		int corner = 1;
		int tmp = i;
		for( int j = 0 ; j < p && tmp>1 ; j++ ) {
			bool flag = false;
			int v = primes[j];
			while(tmp % v == 0) {
				if(flag) {
					other /= v;
					corner *= v;
				}
				else
					other *= v;
				flag = !flag;
				tmp /= v;
			}
		}
		if( tmp > 1 )
			other *= tmp;
		for( int j = 1 ; other*j*j < maxs && other*corner*j < maxs ; j++ )
			sum++, tri[i].pb( pi( other*j*j , other*corner*j ) );
	}
}

void solve() {
	if(center) {
		ans += (LL) yps * xps;
		ans += (LL) xps * yms;
		ans += (LL) yms * xms;
		ans += (LL) xms * yps;
	}
	for( int i = 0 ; i < xps ; i++ ) {
		int x1 = xp[i];
		for( int j = 0 ; j < (int) tri[x1].size() ; j++ ) {
			int x2 = tri[x1][j].fi;
			int y = tri[x1][j].se;
			if( varxm[x2] == tc && varyp[y] == tc )
				ans++;
			if( varxm[x2] == tc && varym[y] == tc )
				ans++;
		}
	}
	for( int i = 0 ; i < yps ; i++ ) {
		int y1 = yp[i];
		for( int j = 0 ; j < (int) tri[y1].size() ; j++ ) {
			int y2 = tri[y1][j].fi;
			int x = tri[y1][j].se;
			if( varym[y2] == tc && varxp[x] == tc )
				ans++;
			if( varym[y2] == tc && varxm[x] == tc )
				ans++;
		}
	}
	printf("%lld\n",ans);
}

int main() {
	precalc();
	scanf("%d",&T);
	for( tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
	}
	return 0;
}
