#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int T,n,k;
int a[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&a[i]);
		sort(a, a+n);
		int cnt = 0, sum = 0;
		while(cnt < n && sum + a[cnt] <= k)
			sum += a[cnt++];
		printf("Case #%d: %d\n",tc,cnt);
	}
	return 0;
}
