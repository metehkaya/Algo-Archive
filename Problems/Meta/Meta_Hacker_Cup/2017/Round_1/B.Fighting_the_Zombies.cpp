#include <bits/stdc++.h>
#define maxn 50
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int T,n,r;
int x[maxn];
int y[maxn];
vector<pi> v;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	v.clear();
}

bool check(int i , int j , int k) {
	bool a = (x[i] >= v[j].fi) && (x[i] <= v[j].fi+r) && (y[i] >= v[j].se) && (y[i] <= v[j].se+r);
	bool b = (x[i] >= v[k].fi) && (x[i] <= v[k].fi+r) && (y[i] >= v[k].se) && (y[i] <= v[k].se+r);
	return a || b;
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&r);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d%d",&x[i],&y[i]);
		for( int i = 0 ; i < n ; i++ )
			for( int j = i ; j < n ; j++ ) {
				int xmn = min(x[i],x[j]);
				int xmx = max(x[i],x[j]);
				int ymn = min(y[i],y[j]);
				int ymx = max(y[i],y[j]);
				if(xmx-xmn <= r && ymx-ymn <= r)
					v.pb(pi(xmn,ymn));
			}
		int k = v.size() , ans = 0;
		for( int i = 0 ; i < k ; i++ )
			for( int j = i ; j < k ; j++ ) {
				int cnt = 0;
				for( int l = 0 ; l < n ; l++ )
					cnt += check(l,i,j);
				ans = max(ans,cnt);
			}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
