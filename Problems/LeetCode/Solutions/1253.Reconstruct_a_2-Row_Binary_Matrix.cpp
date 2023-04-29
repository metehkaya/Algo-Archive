class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& col) {
        int n = col.size();
        vector<int> v[3];
        for( int i = 0 ; i < n ; i++ )
            v[col[i]].push_back(i);
        int cnt2 = v[2].size();
        vector<vector<int>> ans;
        if(min(lower,upper) < cnt2 or upper+lower != v[1].size() + 2*v[2].size())
            return ans;
        ans.resize(2,vector<int>(n,0));
        for( int i = 0 ; i < v[2].size() ; i++ )
            ans[0][v[2][i]] = ans[1][v[2][i]] = 1;
        upper -= cnt2;
        lower -= cnt2;
        for( int i = 0 ; i < upper ; i++ )
            ans[0][v[1][i]] = 1;
        for( int i = 0 ; i < lower ; i++ )
            ans[1][v[1][upper+i]] = 1;
        return ans;
    }
};