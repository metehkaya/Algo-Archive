class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int dp[12][numArrows+1];
        bool take[12][numArrows+1];
        memset(dp,0,sizeof(dp));
        memset(take,false,sizeof(take));
        vector<int> ans(12,0);
        for( int i = 1 ; i < 12 ; i++ ) {
            for( int j = 0 ; j <= numArrows ; j++ )
                dp[i][j] = dp[i-1][j];
            int mn = aliceArrows[i]+1;
            for( int j = mn ; j <= numArrows ; j++ ) {
                int score = dp[i-1][j-mn]+i;
                if(score > dp[i][j])
                    dp[i][j] = score , take[i][j] = true;
            }
        }
        int curr = numArrows;
        for( int i = 11 ; i >= 1 ; i-- )
            if(take[i][curr])
                ans[i] = aliceArrows[i]+1 , curr -= aliceArrows[i]+1;
        ans[0] = curr;
        return ans;
    }
};
