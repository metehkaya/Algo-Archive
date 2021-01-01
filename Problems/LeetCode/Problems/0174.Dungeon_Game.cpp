typedef long long LL;

class Solution {
public:
    bool check(int gain , vector<vector<int>>& ar , int n , int m) {
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = gain + ar[0][0];
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(dp[i][j] > 0) {
                    if(j < m-1)
                        dp[i][j+1] = max(dp[i][j+1] , dp[i][j] + ar[i][j+1]);
                    if(i < n-1)
                        dp[i+1][j] = max(dp[i+1][j] , dp[i][j] + ar[i+1][j]);
                }
        return dp[n-1][m-1] > 0;
    }
    int calculateMinimumHP(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int l = 1 , r = INT_MAX , ans = INT_MAX;
        while(l <= r) {
            int mid = ((LL)l+r) >> 1;
            if(check(mid,ar,n,m))
                ans = mid , r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
};