#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200000
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n,k;
int ar[2*maxn];
int ansLast,ansInit;

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < 2*n ; i++ )
		scanf("%d",&ar[i]);
	ansLast = n;
	for( int t = 0 ; t < n ; t++ ) {
		vector<pi> vec;
		for( int i = 0 ; i < n ; i++ )
			vec.pb(pi(0,0));
		vec[t].fi = ar[0];
		for( int i = 1 , idx = 0 ; i < 2*n ; i++ ) {
			if(vec[idx].fi == 0)
				vec[idx].fi = ar[i];
			else
				vec[idx++].se = ar[i];
		}
		for( int r = 1 ; r <= k ; r++ ) {
			vector<pi> last = vec;
			for( int i = 1 ; i < n ; i++ ) {
				vec[i-1].fi = min(last[i].fi,last[i].se);
				vec[i].se = max(last[i].fi,last[i].se);
			}
			vec[0].se = min(last[0].fi,last[0].se);
			vec[n-1].fi = max(last[0].fi,last[0].se);
		}
		for( int i = 0 ; i < n ; i++ )
			if(vec[i].fi == ar[0] || vec[i].se == ar[0]) {
				if(i <= ansLast) {
					ansLast = i;
					ansInit = t;
				}
				break;
			}
	}
	printf("%d\n",ansInit+1);
	return 0;
}
