class Solution {
public:
    long long mostPoints(vector<vector<int>>& ar) {
        int n = ar.size();
        vector<long long> dp(n,0);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int p = ar[i][0];
            int b = ar[i][1];
            dp[i] = (i == n-1 ? 0 : dp[i+1]);
            int j = i+b+1;
            long long add = (j < n ? dp[j] : 0);
            dp[i] = max(dp[i],add+p);
        }
        return dp[0];
    }
};
