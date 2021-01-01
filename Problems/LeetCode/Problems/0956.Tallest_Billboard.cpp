class Solution {
public:
    const int maxv = 10001;
    int tallestBillboard(vector<int>& ar) {
        int n = ar.size();
        vector<int> dp(maxv,-1);
        dp[maxv/2] = 0;
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> temp = dp;
            for( int j = 0 ; j <= maxv-1-ar[i] ; j++ )
                if(temp[j] != -1)
                    dp[j+ar[i]] = max( dp[j+ar[i]] , temp[j] + ar[i] );
            for( int j = maxv-1 ; j >= ar[i] ; j-- )
                if(temp[j] != -1)
                    dp[j-ar[i]] = max( dp[j-ar[i]] , temp[j] + ar[i] );
        }
        return dp[maxv/2]/2;
    }
};