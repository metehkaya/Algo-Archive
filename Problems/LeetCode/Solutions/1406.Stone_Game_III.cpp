class Solution {
public:
    string stoneGameIII(vector<int>& ar) {
        int n = ar.size();
        vector<int> dp(n+1,INT_MIN);
        dp[n] = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int sum = 0;
            for( int j = 0 ; j < 3 && i + j < n ; j++ ) {
                sum += ar[i+j];
                dp[i] = max( dp[i] , sum - dp[i+j+1] );
            }
        }
        if(dp[0] > 0)
            return "Alice";
        else if(dp[0] == 0)
            return "Tie";
        return "Bob";
    }
};