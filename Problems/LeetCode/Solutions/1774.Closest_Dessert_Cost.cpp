class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = baseCosts.size();
        int m = toppingCosts.size();
        int t = 20000;
        vector<bool> dp(t+1,false);
        dp[0] = true;
        for( int times = 0 ; times < 2 ; times++ )
            for( int i = 0 ; i < m ; i++ )
                for( int j = t-toppingCosts[i] ; j >= 0 ; j-- )
                    if(dp[j])
                        dp[j+toppingCosts[i]] = true;
        vector<bool> dp2(t+1,false);
        for( int i = 0 ; i < n ; i++ )
            for( int j = t-baseCosts[i] ; j >= 0 ; j-- )
                if(dp[j])
                    dp2[j+baseCosts[i]] = true;
        int minDiff = INT_MAX , ans = -1;
        for( int i = 0 ; i <= t ; i++ )
            if(abs(target-i) < minDiff && dp2[i])
                minDiff = abs(target-i) , ans = i;
        return ans;
    }
};
