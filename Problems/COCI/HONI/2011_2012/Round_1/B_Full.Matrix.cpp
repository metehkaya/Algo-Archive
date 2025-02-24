#include <bits/stdc++.h>
#define maxn 400
using namespace std;

int n,ans;
int ar[maxn][maxn];
int dp1[maxn][maxn];
int dp2[maxn][maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
	    for( int j = 0 ; j < n ; j++ ) {
	        scanf("%d",&ar[i][j]);
	        dp1[i][j] = dp2[i][j] = ar[i][j];
	    }
    for( int k = 2 ; k <= n ; k++ )
        for( int i = 0 ; i <= n-k ; i++ )
            for( int j1 = 0 ; j1 <= n-k ; j1++ ) {
                int j2 = j1+k-1;
                dp1[i][j1] = dp1[i+1][j1+1] + ar[i][j1];
                dp2[i][j2] = dp2[i+1][j2-1] + ar[i][j2];
                ans = max(ans,dp1[i][j1]-dp2[i][j2]);
            }
    printf("%d\n",ans);
	return 0;
}