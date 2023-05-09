#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n,k,K;
vector<pi> ans;

void f(int l , int r) {
	if(l == r)
		return;
	int m = (l+r) >> 1;
	f(l,m);
	f(m+1,r);
	for( int i = l , j = m+1 ; i <= m ; i++ , j++ )
		ans.pb(pi(i,j));
}

int main() {
	scanf("%d",&n);
	for( int i = 13 ; i >= 0 ; i-- )
		if(n & (1<<i)) {
			k = i;
			K = (1<<k);
			break;
		}
	f(1,K);
	f(n-K+1,n);
	int sz = ans.size();
	printf("%d\n",sz);
	for( int i = 0 ; i < sz ; i++ )
		printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}
