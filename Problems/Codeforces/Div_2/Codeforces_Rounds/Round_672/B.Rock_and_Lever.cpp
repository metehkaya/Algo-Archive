#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

LL ans;
int T,n;
int cnt[30];
int ar[maxn];

void reset() {
	ans = 0;
	memset(cnt,0,sizeof(cnt));
}

void input() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
}

void solve() {
	for( int i = 1 ; i <= n ; i++ ) {
		int x = -1;
		for( int j = 29 ; j >= 0 ; j-- )
			if(ar[i] & (1<<j)) {
				x = j;
				break;
			}
		ans += cnt[x]++;
	}
}

void output() {
	printf("%lld\n",ans);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
		output();
	}
	return 0;
}
