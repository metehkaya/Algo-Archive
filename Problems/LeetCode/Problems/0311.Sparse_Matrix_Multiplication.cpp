class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int m = A[0].size();
        int k = B[0].size();
        vector<vector<int>> ans(n,vector<int>(k,0));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < k ; j++ )
                for( int l = 0 ; l < m ; l++ )
                    ans[i][j] += A[i][l]*B[l][j];
        return ans;
    }
};