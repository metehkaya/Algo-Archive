class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& ar, int k) {
        int n = ar.size();
        vector<vector<int>> cost(n,vector<int>(n,0));
        for( int i = 0 ; i < n ; i++ ) {
            int mx = -1 , sum = 0;
            for( int j = i ; j < n ; j++ ) {
                sum += ar[j];
                mx = max(mx,ar[j]);
                cost[i][j] = (j-i+1)*mx - sum;
            }
        }
        vector<vector<int>> dp(n,vector<int>(k+1,INT_MAX));
        for( int i = 0 ; i < n ; i++ )
            for( int l = 0 ; l <= k ; l++ )
                for( int j = 0 ; j <= i ; j++ ) {
                    if(l == 0 && j > 0)
                        break;
                    int oldCost = (j == 0) ? 0 : dp[j-1][l-1];
                    dp[i][l] = min(dp[i][l],oldCost+cost[j][i]);
                }
        int ans = INT_MAX;
        for( int i = 0 ; i <= k ; i++ )
            ans = min(ans,dp[n-1][i]);
        return ans;
    }
};
