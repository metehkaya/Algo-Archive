class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& ar, int n, int m) {
        vector<vector<int>> ans;
        int sz = ar.size();
        if(n*m != sz)
            return ans;
        ans.resize(n);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                ans[i].push_back(ar[i*m+j]);
        return ans;
    }
};