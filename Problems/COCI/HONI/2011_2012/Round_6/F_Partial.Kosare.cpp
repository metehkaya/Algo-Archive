#include <bits/stdc++.h>
#define maxm 15
#define maxn 100
#define maxM (1 << (maxm))
#define mod 1000000007
using namespace std;

int n,m,M;
int ar[maxn];
int dp[maxn][maxM];

int f(int i , int bmask) {
    if(i == n)
        return (bmask == M-1);
    else if(dp[i][bmask] != -1)
        return dp[i][bmask];
    int v0 = f(i+1,bmask);
    int v1 = f(i+1,bmask|ar[i]);
    return dp[i][bmask] = (v0 + v1) % mod;
}

int main() {
	scanf("%d%d",&n,&m);
	M = (1 << m);
	for( int i = 0 , k , x ; i < n ; i++ ) {
	    scanf("%d",&k);
	    while(k--) {
	        scanf("%d",&x);
	        ar[i] |= (1 << (x-1));
	    }
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",f(0,0));
	return 0;
}