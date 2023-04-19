#include <bits/stdc++.h>
#define maxn 5001
#define pb push_back
using namespace std;
typedef long long LL;

LL ans,tot;
int n,m,k;
int p[maxn];
int c[maxn];
bool mark[maxn];
vector<int> v;
vector<LL> sum;

void dfs(int u) {
	v.pb(u);
	tot += c[u];
	mark[u] = true;
	if(!mark[p[u]])
		dfs(p[u]);
}

LL f(int d) {
	LL best = INT_MIN;
	for( int i = m+1 ; i <= 2*m ; i++ )
		for( int j = i ; j > i-d ; j-- ) {
			LL temp = sum[i]-sum[j-1];
			best = max(best,temp);
		}
	return best;
}

void solve(int u) {
	tot = 0;
	v.clear();
	sum.clear();
	dfs(u);
	m = v.size();
	sum.pb(0);
	for( int i = 0 ; i < m ; i++ )
		sum.pb(sum.back()+c[v[i]]);
	for( int i = 0 ; i < m ; i++ )
		sum.pb(sum.back()+c[v[i]]);
	if(k <= m)
		ans = max( ans , f(k) );
	else {
		int times = k/m;
		tot = max(tot,0LL);
		ans = max( ans , f(k%m) + tot*times );
		ans = max( ans , f(m) + tot*(times-1) );
	}
}

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&p[i]);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&c[i]);
	ans = INT_MIN;
	for( int i = 1 ; i <= n ; i++ )
		if(!mark[i])
			solve(i);
	printf("%lld\n",ans);
	return 0;
}
