#include <bits/stdc++.h>
#define maxn 101
using namespace std;

int T,n;
int a[maxn];
int b[maxn];
int c[maxn];
int ans[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&a[i]);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&b[i]);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&c[i]);
		ans[1] = a[1];
		for( int i = 2 ; i < n ; i++ ) {
			if(a[i] != ans[i-1])
				ans[i] = a[i];
			else if(b[i] != ans[i-1])
				ans[i] = b[i];
			else
				ans[i] = c[i];
		}
		if(a[n] != ans[1] && a[n] != ans[n-1])
			ans[n] = a[n];
		else if(b[n] != ans[1] && b[n] != ans[n-1])
			ans[n] = b[n];
		else
			ans[n] = c[n];
		for( int i = 1 ; i <= n ; i++ )
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}
