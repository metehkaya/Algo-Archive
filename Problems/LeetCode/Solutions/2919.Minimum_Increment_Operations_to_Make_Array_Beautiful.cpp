class Solution {
public:
    long long minIncrementOperations(vector<int>& v, int k) {
        int n = v.size();
        vector<long long> dp(n+1,LLONG_MAX);
        dp[0] = 0;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= min(i,3) ; j++ )
                dp[i] = min(dp[i],dp[i-j]+max(k-v[i-1],0));
        return min(dp[n],min(dp[n-1],dp[n-2]));
    }
};
