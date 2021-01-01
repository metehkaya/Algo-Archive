typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int f(int l , int r , vi& sum , vii& dp) {
        if(l == r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        dp[l][r] = 0;
        for( int i = l ; i < r ; i++ ) {
            int suml = sum[i]-sum[l-1];
            int sumr = sum[r]-sum[i];
            if(suml < sumr)
                dp[l][r] = max( dp[l][r] , suml + f(l,i,sum,dp) );
            else if(sumr < suml)
                dp[l][r] = max( dp[l][r] , sumr + f(i+1,r,sum,dp) );
            else {
                dp[l][r] = max( dp[l][r] , suml + f(l,i,sum,dp) );
                dp[l][r] = max( dp[l][r] , sumr + f(i+1,r,sum,dp) );
            }
        }
        return dp[l][r];
    }
    int stoneGameV(vector<int>& ar) {
        int n = ar.size();
        vector<int> sum(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1]+ar[i-1];
        vii dp(n+1,vi(n+1,-1));
        return f(1,n,sum,dp);
    }
};