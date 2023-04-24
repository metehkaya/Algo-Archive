#include <bits/stdc++.h>
#define maxn 200003
using namespace std;

int T,n,k,ans;
int ar[maxn];

int main() {
	cin >> T;
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		ans = 0;
		for( int i = k ; i <= n ; i++ )
			if( ar[i] == 1 ) {
				bool ok = true;
				for( int j = 1 ; ok && j <= k ; j++ )
					if( ar[i-j+1] != j )
						ok = false;
				ans += ok;
			}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;	
}
