class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& v, int target) {
        vector<int> dp(target+1,-1);
        dp[0] = 0;
        for(int x : v)
            for( int i = target-x ; i >= 0 ; i-- )
                if(dp[i] != -1)
                    dp[i+x] = max(dp[i+x],dp[i]+1);
        return dp[target];
    }
};
