class Solution {
public:
    int validSubarraySplit(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n,INT_MAX);
        for( int i = 0 ; i < n ; i++ )
            if(__gcd(v[0],v[i]) > 1)
                dp[i] = 1;
        for( int i = 0 ; i < n-1 ; i++ )
            if(dp[i] != INT_MAX)
                for( int j = i+1 ; j < n ; j++ )
                    if(__gcd(v[i+1],v[j]) > 1)
                        dp[j] = min(dp[j],dp[i]+1);
        return dp[n-1] == INT_MAX ? -1 : dp[n-1];
    }
};
