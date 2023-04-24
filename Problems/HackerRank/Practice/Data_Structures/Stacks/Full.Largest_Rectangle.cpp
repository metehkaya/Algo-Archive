#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

LL ans;
int N,n;
int st[maxn];
int ar[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		while(N > 0) {
			int id = st[N];
			if(ar[i] >= ar[id])
				break;
			N--;
			int left = st[N]+1;
			ans = max(ans,(LL)ar[id]*(i-left));
		}
		st[++N] = i;
	}
	while(N > 0) {
		int id = st[N--];
		int left = st[N]+1;
		ans = max(ans,(LL)ar[id]*(n+1-left));
	}
	printf("%lld\n",ans);
	return 0;
}
