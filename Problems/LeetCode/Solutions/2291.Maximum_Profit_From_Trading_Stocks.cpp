class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        vector<int> dp(budget+1,-1);
        dp[0] = 0;
        for( int i = 0 ; i < n ; i++ )
            if(future[i] > present[i])
                for( int j = budget ; j >= present[i] ; j-- )
                    if(dp[j-present[i]] != -1)
                        dp[j] = max(dp[j],dp[j-present[i]]+future[i]);
        int ans = 0;
        for( int i = 0 ; i <= budget ; i++ )
            if(dp[i] != -1)
                ans = max(ans,dp[i]-i);
        return ans;
    }
};
