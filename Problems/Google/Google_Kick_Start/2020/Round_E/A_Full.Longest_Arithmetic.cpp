#include <bits/stdc++.h>
#define maxn 200001
using namespace std;

int T,n;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		int ans = 1;
		for( int i = 1 , j ; i <= n ; i = j ) {
			j = i+1;
			while(j < n && ar[i+1]-ar[i] == ar[j+1]-ar[j])
				j++;
			ans = max(ans,j-i+1);
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
