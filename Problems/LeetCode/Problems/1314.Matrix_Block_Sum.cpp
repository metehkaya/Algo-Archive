class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& ar, int k) {
        int n = (int) ar.size();
        int m = (int) ar[0].size();
        vector< vector<int> > sum(n+1, vector<int>(m+1,0));
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
                sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + ar[i-1][j-1];
        vector< vector<int> > ans(n, vector<int>(m));
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ ) {
                int i0 = max(i-k,1);
                int j0 = max(j-k,1);
                int i1 = min(i+k,n);
                int j1 = min(j+k,m);
                ans[i-1][j-1] = sum[i1][j1] - sum[i1][j0-1] - sum[i0-1][j1] + sum[i0-1][j0-1];
            }
        return ans;
    }
};