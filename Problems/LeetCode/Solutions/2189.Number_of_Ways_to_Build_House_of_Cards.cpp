class Solution {
public:
    int houseOfCards(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for( int k = 2 ; k <= n ; k += 3 )
            for( int i = n ; i >= k ; i-- )
                dp[i] += dp[i-k];
        return dp[n];
    }
};
