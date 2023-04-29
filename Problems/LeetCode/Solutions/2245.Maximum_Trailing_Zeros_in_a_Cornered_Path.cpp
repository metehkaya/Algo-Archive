class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vals[2] = {2,5};
        int sumr[n][m+1][2];
        int sumc[m][n+1][2];
        int cnt[n][m][2];
        memset(sumr,0,sizeof(sumr));
        memset(sumc,0,sizeof(sumc));
        memset(cnt,0,sizeof(cnt));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                int x = grid[i][j];
                for( int k = 0 ; k < 2 ; k++ ) {
                    while(x % vals[k] == 0)
                        x /= vals[k] , cnt[i][j][k]++;
                    sumr[i][j+1][k] = sumr[i][j][k]+cnt[i][j][k];
                    sumc[j][i+1][k] = sumc[j][i][k]+cnt[i][j][k];
                }
            }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                int right[2] = {sumr[i][m][0]-sumr[i][j+1][0] , sumr[i][m][1]-sumr[i][j+1][1]};
                int left[2] = {sumr[i][j][0]-sumr[i][0][0] , sumr[i][j][1]-sumr[i][0][1]};
                int bottom[2] = {sumc[j][n][0]-sumc[j][i+1][0] , sumc[j][n][1]-sumc[j][i+1][1]};
                int top[2] = {sumc[j][i][0]-sumc[j][0][0] , sumc[j][i][1]-sumc[j][0][1]};
                ans = max(ans,min(top[0]+right[0]+cnt[i][j][0] , top[1]+right[1]+cnt[i][j][1]));
                ans = max(ans,min(top[0]+left[0]+cnt[i][j][0] , top[1]+left[1]+cnt[i][j][1]));
                ans = max(ans,min(bottom[0]+right[0]+cnt[i][j][0] , bottom[1]+right[1]+cnt[i][j][1]));
                ans = max(ans,min(bottom[0]+left[0]+cnt[i][j][0] , bottom[1]+left[1]+cnt[i][j][1]));
            }
        return ans;
    }
};
