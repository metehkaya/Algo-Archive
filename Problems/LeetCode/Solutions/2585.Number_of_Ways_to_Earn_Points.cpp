class Solution {
public:
    const int mod = (int) 1e9+7;
    int waysToReachTarget(int m, vector<vector<int>>& types) {
        vector<int> dp(m+1,0);
        dp[0] = 1;
        for(auto v : types) {
            vector<int> dp_new(m+1,0);
            int cnt = v[0] , p = v[1];
            for( int i = 0 ; i <= m ; i++ )
                for( int j = i ; j <= i+cnt*p and j <= m ; j += p )
                    dp_new[j] = (dp_new[j] + dp[i]) % mod;
            swap(dp,dp_new);
        }
        return dp[m];
    }
};
