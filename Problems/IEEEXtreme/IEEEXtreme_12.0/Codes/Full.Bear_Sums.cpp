// Teammate : Osman Orhan Uysal

#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;

const int maxn = 200020;

int a,b,ar[maxn];
map<int,int> mp;

void solve() {
	scanf("%d %d",&a,&b);
	mp.clear();
	ii ans;
	int h = 0;
	for( int i = 1 ; i <= b ; i++ ) {
		scanf("%d",&ar[i]);
		if( !h && mp[ a-ar[i] ] ) {
			ans = ii( a-ar[i], ar[i] );
			if( ans.fi > ans.se )
				swap( ans.fi, ans.se );
			h = 1;
		}
		mp[ ar[i] ]++;
	}
	if(h)
		printf("%d %d\n",ans.fi,ans.se);
	else
		printf("!OK\n");
}

int main() {
	int n = 1;
	scanf("%d",&n);
	while(n--)
		solve();
	return 0;
}
