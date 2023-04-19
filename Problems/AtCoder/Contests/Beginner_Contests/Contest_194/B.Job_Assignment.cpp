#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n,ans;
vector<pi> a,b;

int main() {
	scanf("%d",&n);
	for( int i = 0 , x,y ; i < n ; i++ ) {
		scanf("%d%d",&x,&y);
		a.pb(pi(x,i));
		b.pb(pi(y,i));
	}
	ans = INT_MAX;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for( int i = 0 ; i < 2 ; i++ )
		for( int j = 0 ; j < 2 ; j++ )
			if(a[i].se == b[j].se)
				ans = min(ans,a[i].fi+b[j].fi);
			else
				ans = min(ans,max(a[i].fi,b[j].fi));
	printf("%d\n",ans);
	return 0;
}
