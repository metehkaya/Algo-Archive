#include <bits/stdc++.h>
#define maxn 10000003
using namespace std;
typedef long long LL;

int n,m;
LL add[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 , x , y , k ; i <= m ; i++ ) {
		scanf("%d%d%d",&x,&y,&k);
		add[x] += k;
		add[y+1] -= k;
	}
	LL res = add[1] , curr = add[1];
	for( int i = 2 ; i <= n ; i++ ) {
		curr += add[i];
		res = max(res,curr);
	}
	printf("%lld\n",res);
	return 0;
}
