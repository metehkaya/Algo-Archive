class Solution {
public:
    int n,m;
    int dp[1001][1001];
    vector<int> v;
    int kthLargestValue(vector<vector<int>>& ar, int k) {
        n = ar.size();
        m = ar[0].size();
        vector<int> v;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ ) {
                dp[i][j] = (dp[i-1][j] ^ dp[i][j-1] ^ dp[i-1][j-1] ^ ar[i-1][j-1]);
                v.push_back(dp[i][j]);
            }
        sort(v.begin(),v.end());
        return v[n*m-k];
    }
};