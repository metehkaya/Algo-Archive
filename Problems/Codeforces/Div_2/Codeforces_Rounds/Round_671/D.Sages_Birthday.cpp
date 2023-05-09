#include <bits/stdc++.h>
#define maxn 100003
using namespace std;

int T,n,cnt;
int ar[maxn];
int ans[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	sort(ar+1,ar+n+1);
	for( int i = 1 ; i <= n ; i++ ) {
		if(i%2)
			ans[i] = ar[n/2+(i+1)/2];
		else
			ans[i] = ar[i/2];
	}
	for( int i = 2 ; i < n ; i++ )
		cnt += ( ans[i] < min(ans[i-1],ans[i+1]) );
	printf("%d\n",cnt);
	for( int i = 1 ; i <= n ; i++ )
		printf("%d ",ans[i]);
	return 0;
}
