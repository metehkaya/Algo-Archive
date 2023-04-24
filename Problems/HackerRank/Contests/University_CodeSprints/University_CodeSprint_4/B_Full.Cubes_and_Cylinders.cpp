#include <bits/stdc++.h>
#define maxn 500
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<double,int> pi;
typedef pair<pi,int> pii;

int n,m;
int s[maxn];
int k[maxn];
int r[maxn];
int c[maxn];
vector<pii> len;

bool comp(pii a , pii b) {
	if(a.fi.fi != b.fi.fi)
		return a.fi.fi < b.fi.fi;
	return a.se < b.se;
}

void read() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&s[i]);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&k[i]);
	for( int i = 0 ; i < m ; i++ )
		scanf("%d",&r[i]);
	for( int i = 0 ; i < m ; i++ )
		scanf("%d",&c[i]);
}

void solve() {
	for( int i = 0 ; i < n ; i++ )
		len.pb(pii(pi(sqrt(2)*s[i],k[i]),0));
	for( int i = 0 ; i < m ; i++ )
		len.pb(pii(pi(2.0*r[i],c[i]),1));
	sort(len.begin(),len.end(),comp);
	int ans = 0;
	for( int i = 0 , cap = 0 ; i < len.size() ; i++ ) {
		if(!len[i].se)
			cap += len[i].fi.se;
		else {
			int mn = min(cap,len[i].fi.se);
			cap -= mn;
			ans += mn;
		}
	}
	printf("%d\n",ans);
}

int main() {
	read();
	solve();
	return 0;
}
