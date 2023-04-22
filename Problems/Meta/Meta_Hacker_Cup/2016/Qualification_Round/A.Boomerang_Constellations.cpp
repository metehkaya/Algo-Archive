#include <bits/stdc++.h>
#define maxn 2000
using namespace std;
typedef long long LL;

int T,n;
int x[maxn];
int y[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d%d",&x[i],&y[i]);
		LL ans = 0;
		for( int i = 0 ; i < n ; i++ ) {
			map<int,int> cnt;
			for( int j = 0 ; j < n ; j++ )
				if(i != j) {
					int dx = x[i]-x[j];
					int dy = y[i]-y[j];
					int d = dx*dx+dy*dy;
					ans += cnt[d]++;
				}
		}
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
