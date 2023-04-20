#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200000
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int n;
LL ans;
pi ar[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d%d",&ar[i].fi,&ar[i].se);
	sort(ar,ar+n);
	LL t = 0;
	for( int i = 0 ; i < n ; i++ ) {
		t += ar[i].fi;
		ans += ar[i].se - t;
	}
	printf("%lld\n",ans);
	return 0;
}