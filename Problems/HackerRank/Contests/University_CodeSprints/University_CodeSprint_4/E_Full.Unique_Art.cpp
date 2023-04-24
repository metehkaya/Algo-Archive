#include <bits/stdc++.h>
#define fi first
#define se second
#define maxs 1000
#define maxn 1000003
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

int n,m,k;
int ar[maxn];
int cnt[maxn];
int ans[maxn];
pii q[maxn];
map<int,int> hashh;

bool comp(pii a , pii b) {
	if(a.fi.fi/maxs != b.fi.fi/maxs)
		return a.fi.fi < b.fi.fi;
	return a.fi.se < b.fi.se;
}

void read() {
	scanf("%d",&n);
	for( int i = 1 , x ; i <= n ; i++ ) {
		scanf("%d",&x);
		ar[i] = hashh[x];
		if(!ar[i])
			ar[i] = hashh[x] = ++k;
	}
	scanf("%d",&m);
	for( int i = 1 ; i <= m ; i++ ) {
		scanf("%d%d",&q[i].fi.fi,&q[i].fi.se);
		q[i].se = i;
	}
}

void solve() {
	sort(q+1,q+m+1,comp);
	for( int i = 1 , l = 1 , r = 0 , res = 0 , val ; i <= m ; i++ ) {
		while(r < q[i].fi.se) {
			val = ar[++r];
			if(++cnt[val] == 1)
				res++;
			else if(cnt[val] == 2)
				res--;
		}
		while(l > q[i].fi.fi) {
			val = ar[--l];
			if(++cnt[val] == 1)
				res++;
			else if(cnt[val] == 2)
				res--;
		}
		while(r > q[i].fi.se) {
			val = ar[r--];
			if(--cnt[val] == 1)
				res++;
			else if(cnt[val] == 0)
				res--;
		}
		while(l < q[i].fi.fi) {
			val = ar[l++];
			if(--cnt[val] == 1)
				res++;
			else if(cnt[val] == 0)
				res--;
		}
		ans[q[i].se] = res;
	}
}

void output() {
	for( int i = 1 ; i <= m ; i++ )
		printf("%d\n",ans[i]);
}

int main() {
	read();
	solve();
	output();
	return 0;
}
