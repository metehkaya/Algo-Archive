class Solution {
public:
    int change(int m, vector<int>& ar) {
        int n = ar.size();
        vector<int> dp(m+1);
        dp[0] = 1;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j <= m-ar[i] ; j++ )
                dp[j+ar[i]] += dp[j];
        return dp[m];
    }
};