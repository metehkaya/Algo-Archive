class Solution {
public:
    int n;
    vector<int> ar;
    int dp[20][20];
    bool PredictTheWinner(vector<int>& ar) {
        n = ar.size();
        this->ar = ar;
        for( int i = 0 ; i < n ; i++ )
            dp[i][i] = ar[i];
        for( int len = 2 ; len <= n ; len++ )
            for( int i = 0 ; i <= n-len ; i++ ) {
                int j = i+len-1;
                dp[i][j] = max(ar[i]-dp[i+1][j],ar[j]-dp[i][j-1]);
            }
        return dp[0][n-1] >= 0;
    }
};