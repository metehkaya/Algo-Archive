class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& ar) {
        int n = ar.size();
        map<int,vector<int>> vecs;
        for( int i = 0 ; i < n ; i++ ) {
            int sz = ar[i].size();
            for( int j = 0 ; j < sz ; j++ )
                vecs[i+j].push_back(ar[i][j]);
        }
        vector<int> ans;
        map<int,vector<int>>::iterator it;
        for( it = vecs.begin() ; it != vecs.end() ; it++ ) {
            vector<int> v = it->second;
            int sz = v.size();
            for( int i = sz-1 ; i >= 0 ; i-- )
                ans.push_back(v[i]);
        }
        return ans;
    }
};