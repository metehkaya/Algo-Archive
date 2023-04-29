class Solution {
public:
    int coinChange(vector<int>& ar, int m) {
        int n = ar.size();
        vector<int>dp(m+1,-1);
        dp[0] = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j <= m-ar[i] ; j++ )
                if( dp[j] != -1 )
                    if( dp[j+ar[i]] == -1 || dp[j+ar[i]] > dp[j]+1 )
                        dp[j+ar[i]] = dp[j]+1;
        return dp[m];
    }
};