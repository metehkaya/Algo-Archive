class Solution {
public:
    int f(int l , int r , int k , vector<vector<int>>& dp , vector<int>& sum) {
        int len = r-l+1;
        if(len < k)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        dp[l][r] = INT_MAX;
        for( int i = l ; i < r ; i += k-1 )
            dp[l][r] = min( dp[l][r] , f(l,i,k,dp,sum) + f(i+1,r,k,dp,sum) );
        if((len-k)%(k-1) == 0)
            dp[l][r] += sum[r+1]-sum[l];
        return dp[l][r];
    }
    int mergeStones(vector<int>& ar, int k) {
        int n = ar.size();
        if((n-1)%(k-1))
            return -1;
        vector<int> sum(n+1);
        sum[0] = 0;
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,n-1,k,dp,sum);
    }
};