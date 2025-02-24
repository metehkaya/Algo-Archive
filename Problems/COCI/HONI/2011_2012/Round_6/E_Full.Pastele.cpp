#include <bits/stdc++.h>
#define maxs 256
using namespace std;

int n,K,si,sj,sk;
int ar[maxs+1][maxs+1][maxs+1];
int dp[maxs+1][maxs+1][maxs+1];

int query(int i2 , int j2 , int k2 , int i1 , int j1 , int k1) {
    return  +dp[i2][j2][k2]
            -(dp[i1][j2][k2] + dp[i2][j1][k2] + dp[i2][j2][k1])
            +(dp[i1][j1][k2] + dp[i1][j2][k1] + dp[i2][j1][k1])
            -dp[i1][j1][k1];
}

bool check(int diff) {
    for( int i = 1 ; i <= maxs-diff ; i++ )
        for( int j = 1 ; j <= maxs-diff ; j++ )
            for( int k = 1 ; k <= maxs-diff ; k++ )
                if(query(i+diff,j+diff,k+diff,i-1,j-1,k-1) >= K) {
                    si = i;
                    sj = j;
                    sk = k;
                    return true;
                }
    return false;
}

void print_sol(int ans) {
    printf("%d\n",ans);
    int rem = K;
    for( int i = si ; i <= si+ans ; i++ )
        for( int j = sj ; j <= sj+ans ; j++ )
            for( int k = sk ; k <= sk+ans ; k++ )
                while(ar[i][j][k] > 0 and rem > 0) {
                    rem--;
                    ar[i][j][k]--;
                    printf("%d %d %d\n",i-1,j-1,k-1);
                }
}

int main() {
	scanf("%d%d",&n,&K);
	for( int i = 0 , x,y,z ; i < n ; i++ ) {
	    scanf("%d%d%d",&x,&y,&z);
	    ar[++x][++y][++z]++;
	}
	for( int i = 1 ; i <= maxs ; i++ )
	    for( int j = 1 ; j <= maxs ; j++ )
	        for( int k = 1 ; k <= maxs ; k++ )
	            dp[i][j][k] =   +ar[i][j][k]
	                            +(dp[i-1][j][k] + dp[i][j-1][k] + dp[i][j][k-1])
	                            -(dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i][j-1][k-1])
	                            +dp[i-1][j-1][k-1];
	int l = 0 , r = maxs-1 , ans = maxs;
	while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid))
            r = mid-1 , ans = mid;
        else
            l = mid+1;
	}
	print_sol(ans);
	return 0;
}