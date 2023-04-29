class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size();
        vector<vector<int>> v(n+m-1);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                v[i-j+m-1].push_back(ar[i][j]);
        for( int i = 0 ; i < n+m-1 ; i++ )
            sort(v[i].begin(),v[i].end());
        vector<vector<int>> ans(n,vector<int>(m));
        for( int i = n-1 ; i >= 0 ; i-- )
            for( int j = m-1 ; j >= 0 ; j-- ) {
                int g = i-j+m-1;
                ans[i][j] = v[g].back();
                v[g].pop_back();
            }
        return ans;
    }
};