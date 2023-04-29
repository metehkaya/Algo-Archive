class Solution {
public:
    int mincostTickets(vector<int>& ar, vector<int>& costs) {
        int n = ar.size();
        vector<int> dp(n+1);
        dp[n] = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            dp[i] = dp[i+1] + costs[0];
            int j = i;
            while(j < n && ar[j] < ar[i]+7)
                j++;
            dp[i] = min( dp[i] , dp[j] + costs[1] );
            while(j < n && ar[j] < ar[i]+30)
                j++;
            dp[i] = min( dp[i] , dp[j] + costs[2] );
        }
        return dp[0];
    }
};