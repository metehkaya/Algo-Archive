#include <bits/stdc++.h>
#define maxn 200001
using namespace std;

int T,n;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		int mx = -1 , ans = 0;
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		for( int i = 1 ; i <= n ; i++ ) {
			if(ar[i] > mx)
				if(i == n || ar[i] > ar[i+1])
					ans++;
			mx = max(mx,ar[i]);
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
