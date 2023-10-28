class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int n = prices.size() , ans = -1;
        vector<int> dp1(n,0) , dp2(n,0);
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if(prices[i] < prices[j]) {
                    dp1[i] = max(dp1[i],profits[j]);
                    dp2[j] = max(dp2[j],profits[i]);
                }
        for( int i = 0 ; i < n ; i++ )
            if(dp1[i] > 0 and dp2[i] > 0)
                ans = max(ans,dp1[i]+dp2[i]+profits[i]);
        return ans;
    }
};
