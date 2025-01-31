class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxk = log2(n);
        vector<vector<int>> dp(n,vector<int>(maxk+1));
        for( int i = 0 ; i < n ; i++ )
            dp[i][0] = nums[i];
        for( int k = 1 ; k <= maxk ; k++ )
            for( int i = 0 ; i+(1<<k) <= n ; i++ )
                dp[i][k] = (dp[i][k-1] | dp[i+(1<<(k-1))][k-1]);
        int ans = n+1;
        for( int i = 0 ; i < n ; i++ ) {
            int l = i , r = n-1;
            while(l <= r) {
                int m = (l+r)/2;
                int len = m-i+1;
                int k = log2(len);
                int val = (dp[i][k] | dp[m-(1<<k)+1][k]);
                if(val >= threshold) {
                    ans = min(ans,len);
                    r = m-1;
                }
                else
                    l = m+1;
            }
        }
        return ans == n+1 ? -1 : ans;
    }
};
