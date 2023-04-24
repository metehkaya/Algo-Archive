#include <bits/stdc++.h>
#define maxn 500003
using namespace std;
typedef long long LL;

int n,m;
LL tot,add;
int ar[maxn];
LL sum[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		tot += abs(ar[i]);
	}
	sort( ar+1 , ar+n+1 );
	for( int i = 1 ; i <= n ; i++ )
		sum[i] = sum[i-1] + ar[i];
	scanf("%d",&m);
	for( int i = 0 , x ; i < m ; i++ ) {
		scanf("%d",&x);
		add += x;
		if(add == 0)
			printf("%lld\n",tot);
		else if(add > 0) {

		}
	}
	return 0;
}
