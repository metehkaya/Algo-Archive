class Solution {
public:
    int n;
    long long sum[2][50001];
    long long gridGame(vector<vector<int>>& ar) {
        n = ar[0].size();
        for( int i = 0 ; i < 2 ; i++ )
            for( int j = 1 ; j <= n ; j++ )
                sum[i][j] = sum[i][j-1] + ar[i][j-1];
        long long ans = LLONG_MAX;
        for( int i = 1 ; i <= n ; i++ ) {
            long long sum0 = sum[0][n] - sum[0][i];
            long long sum1 = sum[1][i-1];
            ans = min(ans,max(sum0,sum1));
        }
        return ans;
    }
};