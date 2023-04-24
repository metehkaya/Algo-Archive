#include <bits/stdc++.h>
using namespace std;

int T,n,m,N,M;
int ans[4];
int ar[3][4];
int minAr[4];

const int MIL = 1e6;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		for( int i = 0 ; i < 4 ; i++ )
			minAr[i] = INT_MAX;
		for( int i = 0 ; i < 3 ; i++ )
			for( int j = 0 ; j < 4 ; j++ ) {
				scanf("%d",&ar[i][j]);
				minAr[j] = min(minAr[j],ar[i][j]);
			}
		int rem = MIL;
		for( int i = 0 ; i < 4 ; i++ ) {
			ans[i] = min(rem,minAr[i]);
			rem -= ans[i];
		}
		printf("Case #%d:",tc);
		if(rem > 0)
			printf(" IMPOSSIBLE");
		else
			for( int i = 0 ; i < 4 ; i++ )
				printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}
