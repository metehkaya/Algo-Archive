#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

int n,m;
int ar[maxn];
LL sum[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		sum[i] = sum[i-1] + ar[i];
	}
	for( int i = 0 , l,r ; i < m ; i++ ) {
		scanf("%d%d",&l,&r);
		printf("%lld\n",sum[r]-sum[l-1]);
	}
	return 0;
}
