#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

int T,n;
int deg[maxn];
int val[maxn];
priority_queue<int> heap;

void reset() {
	for( int i = 1 ; i <= n ; i++ )
		deg[i] = 0;
}

int main() {
	scanf("%d",&T);
	for( int tc = 0 ; tc < T ; tc++ ) {
		reset();
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&val[i]);
		for( int i = 1 , u,v ; i < n ; i++ ) {
			scanf("%d%d",&u,&v);
			deg[u]++;
			deg[v]++;
		}
		LL ans = 0;
		for( int i = 1 ; i <= n ; i++ ) {
			ans += val[i];
			for( int j = 1 ; j < deg[i] ; j++ )
				heap.push(val[i]);
		}
		printf("%lld ",ans);
		for( int c = 2 ; c < n ; c++ ) {
			ans += heap.top();
			heap.pop();
			printf("%lld ",ans);
		}
		puts("");
	}
	return 0;
}
