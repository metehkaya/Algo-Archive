class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& v) {
        int n = v.size() , m = v[0].size();
        vector<int> ans(m,0);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                ans[j] = max(ans[j],(int)to_string(v[i][j]).length());
        return ans;
    }
};
