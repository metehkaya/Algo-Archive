#include <bits/stdc++.h>
using namespace std;

int T,n,m;
int type[51];
int total[51];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&m);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&type[i]);
		memset(total, -1, sizeof(total));
		for( int i = 1 , price ; i <= n ; i++ ) {
			scanf("%d",&price);
			int t = type[i];
			if(total[t] == -1)
				total[t] = price;
			else
				total[t] += price;
		}
		int ans = -1;
		for( int i = 1 ; i <= m ; i++ )
			if( total[i] != -1 )
				if( ans == -1 || total[i] < ans )
					ans = total[i];
		printf("%d\n",ans);
	}
	return 0;
}
