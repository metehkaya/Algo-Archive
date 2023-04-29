class Solution {
public:
    int wiggleMaxLength(vector<int>& ar) {
        int n = ar.size() , ans = 1;
        int dp[n][2];
        for( int i = 0 ; i < n ; i++ ) {
            dp[i][0] = dp[i][1] = 1;
            for( int j = 0 ; j < i ; j++ )
                if(ar[j] < ar[i])
                    dp[i][0] = max(dp[i][0],dp[j][1]+1);
                else if(ar[j] > ar[i])
                    dp[i][1] = max(dp[i][1],dp[j][0]+1);
            ans = max(ans,dp[i][0]);
            ans = max(ans,dp[i][1]);
        }
        return ans;
    }
};