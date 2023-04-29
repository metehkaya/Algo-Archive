class Solution {
public:
    int n,m;
    bool dp[70][4901];
    int minimizeTheDifference(vector<vector<int>>& ar, int target) {
        n = ar.size();
        m = ar[0].size();
        for( int i = 0 ; i < m ; i++ )
            dp[0][ar[0][i]] = true;
        for( int i = 1 ; i < n ; i++ )
            for( int k = 0 ; k < 70*i ; k++ )
                if(dp[i-1][k])
                    for( int j = 0 ; j < m ; j++ )
                        dp[i][k+ar[i][j]] = true;
        int ans = INT_MAX;
        for( int i = 0 ; i <= 4900 ; i++ )
            if(dp[n-1][i])
                ans = min(ans,abs(target-i));
        return ans;
    }
};