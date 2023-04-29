class Solution {
public:
    bool validPartition(vector<int>& ar) {
        int n = ar.size();
        vector<int> dp(n+1,false);
        dp[0] = true;
        for( int i = 2 ; i <= n ; i++ ) {
            if(dp[i-2] && ar[i-2] == ar[i-1])
                dp[i] = true;
            else if(i >= 3 && dp[i-3] && ar[i-3] == ar[i-2] && ar[i-2] == ar[i-1])
                dp[i] = true;
            else if(i >= 3 && dp[i-3] && ar[i-3]+1 == ar[i-2] && ar[i-2]+1 == ar[i-1])
                dp[i] = true;
        }
        return dp[n];
    }
};
