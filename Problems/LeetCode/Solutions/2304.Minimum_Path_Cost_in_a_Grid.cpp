class Solution {
public:
    int n,m;
    int dp[50][50];
    int minPathCost(vector<vector<int>>& ar, vector<vector<int>>& cost) {
        n = ar.size() , m = ar[0].size();
        for( int i = 0 ; i < m ; i++ )
            dp[0][i] = ar[0][i];
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                dp[i][j] = INT_MAX;
                for( int k = 0 ; k < m ; k++ ) {
                    int val = ar[i-1][k];
                    dp[i][j] = min(dp[i][j],dp[i-1][k]+ar[i][j]+cost[val][j]);
                }
            }
        int ans = INT_MAX;
        for( int i = 0 ; i < m ; i++ )
            ans = min(ans,dp[n-1][i]);
        return ans;
    }
};
