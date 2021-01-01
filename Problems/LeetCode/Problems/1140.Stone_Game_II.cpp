typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int f(int p , int i , int j , int n , vii (&dp)[2] , vi& sum) {
        if(i == n)
            return 0;
        if(p == 0 && dp[p][i][j] != 0)
            return dp[p][i][j];
        if(p == 1 && dp[p][i][j] != INT_MAX)
            return dp[p][i][j];
        for( int k = 1 ; k <= min(n-i,2*j) ; k++ ) {
            if(p == 0)
                dp[p][i][j] = max( dp[p][i][j] , f(!p,i+k,max(j,k),n,dp,sum) + sum[i+k] - sum[i] );
            else
                dp[p][i][j] = min( dp[p][i][j] , f(!p,i+k,max(j,k),n,dp,sum) );
        }
        return dp[p][i][j];
    }
    int stoneGameII(vi& ar) {
        int n = ar.size();
        vi sum(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        vii dp[2];
        dp[0].resize(n+1,vi(n+1,0));
        dp[1].resize(n+1,vi(n+1,INT_MAX));
        return f(0,0,1,n,dp,sum);
    }
};