#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 5000
using namespace std;
typedef pair<int,int> pi;

int n,x;
pi ar[maxn];

int main() {
	scanf("%d%d",&n,&x);
	for( int i = 0 ; i < n ; i++ ) {
		scanf("%d",&ar[i].fi);
		ar[i].se = i+1;
	}
	sort(ar,ar+n);
	for( int i = 0 ; i < n ; i++ ) {
		int k = n-1;
		for( int j = i+1 ; j < n ; j++ ) {
			while( k > j && ar[i].fi+ar[j].fi > x-ar[k].fi )
				k--;
			if( k <= j )
				break;
			if( ar[i].fi+ar[j].fi == x-ar[k].fi ) {
				printf("%d %d %d\n",ar[i].se,ar[j].se,ar[k].se);
				return 0;
			}
		}
	}
	puts("IMPOSSIBLE");
	return 0;
}