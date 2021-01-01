class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& ar, int k) {
        int n = ar.size();
        vector<int> dp(n+1,0);
        for( int i = 0 ; i < n ; i++ ) {
            int mx = 0;
            for( int j = 1 ; j <= min(n-i,k) ; j++ ) {
                mx = max(mx,ar[i+j-1]);
                dp[i+j] = max( dp[i+j] , dp[i] + mx*j );
            }
        }
        return dp[n];
    }
};