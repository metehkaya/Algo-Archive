class Solution {
public:
    int n,ans;
    int mx_row[50];
    int mx_col[50];
    int maxIncreaseKeepingSkyline(vector<vector<int>>& ar) {
        n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ ) {
                mx_row[i] = max(mx_row[i],ar[i][j]);
                mx_col[j] = max(mx_col[j],ar[i][j]);
            }
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                ans += min(mx_row[i],mx_col[j]) - ar[i][j];
        return ans;
    }
};