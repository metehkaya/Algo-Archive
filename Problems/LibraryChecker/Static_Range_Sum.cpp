#include <bits/stdc++.h>
#define maxn 500001
using namespace std;
typedef long long LL;

int n,m;
LL sum[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%lld",&sum[i]);
		sum[i] += sum[i-1];
	}
	for( int i = 0 , l,r ; i < m ; i++ ) {
		scanf("%d%d",&l,&r);
		printf("%lld\n",sum[r]-sum[l]);
	}
	return 0;
}
