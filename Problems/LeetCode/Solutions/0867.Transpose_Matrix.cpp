class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for( int i = 0 ; i < m ; i++ )
            for( int j = 0 ; j < n ; j++ )
                ans[i][j] = ar[j][i];
        return ans;
    }
};