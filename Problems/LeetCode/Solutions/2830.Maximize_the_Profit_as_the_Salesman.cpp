class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        vector<int> ids[n];
        for( int i = 0 ; i < m ; i++ )
            ids[offers[i][0]].push_back(i);
        vector<int> dp(n+1,0);
        for( int i = 0 ; i < n ; i++ ) {
            dp[i+1] = max(dp[i+1],dp[i]);
            for(int id : ids[i]) {
                int j = offers[id][1];
                int val = offers[id][2];
                dp[j+1] = max(dp[j+1],dp[i]+val);
            }
        }
        return dp[n];
    }
};