class Solution {
public:
    int maxHeight(vector<vector<int>>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            sort(ar[i].begin(),ar[i].end());
        sort(ar.begin(),ar.end());
        int ans = 0;
        int dp[n];
        ans = dp[0] = ar[0][2];
        for( int i = 1 ; i < n ; i++ ) {
            dp[i] = ar[i][2];
            for( int j = 0 ; j < i ; j++ )
                if(ar[i][0] >= ar[j][0] && ar[i][1] >= ar[j][1] && ar[i][2] >= ar[j][2])
                    dp[i] = max(dp[i],dp[j]+ar[i][2]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};