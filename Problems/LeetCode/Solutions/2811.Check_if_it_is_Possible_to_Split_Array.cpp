class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> sum(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + nums[i-1];
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        for( int l = 1 ; l <= n ; l++ )
            for( int i = 1 ; i <= n-l+1 ; i++ ) {
                int j = i+l-1;
                if(l <= 2)
                    dp[i][j] = true;
                else {
                    for( int k = i ; k < j ; k++ ) {
                        int sum1 = sum[k]-sum[i-1];
                        int sum2 = sum[j]-sum[k];
                        bool ok1 = ((k == i) or (sum1 >= m));
                        bool ok2 = ((k+1 == j) or (sum2 >= m));
                        if(ok1 and ok2 and dp[i][k] and dp[k+1][j]) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                }
            }
        return dp[1][n];
    }
};
