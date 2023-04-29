#include <bits/stdc++.h>
#define maxs 3000001
#define pb push_back
using namespace std;
typedef long long LL;

int n,m;
int val[maxs];
vector<int> f;

int main() {
	m = 2;
	f.pb(1);
	f.pb(2);
	while(f[m-1]+f[m-2] < maxs) {
		f.pb(f[m-1]+f[m-2]);
		m++;
	}
	for( int i = 1 ; i < maxs ; i++ ) {
		LL bmask = 0;
		for( int j = 0 ; j < m && f[j] <= i ; j++ )
			bmask |= (1LL<<val[i-f[j]]);
		for( int j = 0 ; true ; j++ )
			if((bmask & (1LL<<j)) == 0) {
				val[i] = j;
				break;
			}
	}
	int ans = 0;
	scanf("%d",&n);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		ans ^= val[x];
	}
	if(ans)
		puts("Ada");
	else
		puts("Vinit");
	return 0;
}
