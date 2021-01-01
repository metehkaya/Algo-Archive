class Solution {
public:
    int numSubmat(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<vector<int>> sum(m+1,vector<int>(n+1,0));
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
                sum[j][i] = sum[j][i-1] + ar[i-1][j-1];
        int ans = 0;
        for( int l = 1 ; l <= n ; l++ )
            for( int r = l ; r <= n ; r++ ) {
                int len = r-l+1 , curr = 0;
                for( int i = 1 ; i <= m ; i++ ) {
                    if(sum[i][r] - sum[i][l-1] != len)
                        curr = 0;
                    else
                        curr++;
                    ans += curr;
                }
            }
        return ans;
    }
};