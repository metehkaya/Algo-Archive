class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& ar, int k) {
        vector<int> dp(k+1,INT_MIN);
        dp[0] = 0;
        for(vector<int> v : ar) {
            int sz = v.size();
            vector<int> sum(sz+1,0);
            for( int i = 1 ; i <= sz ; i++ )
                sum[i] = sum[i-1] + v[i-1];
            for( int i = k ; i >= 1 ; i-- ) {
                int u = min(i,sz);
                for( int j = 1 ; j <= u ; j++ )
                    dp[i] = max(dp[i],dp[i-j]+sum[j]);
            }
        }
        return dp[k];
    }
};
