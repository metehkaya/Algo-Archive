class Solution {
public:
    bool removeOnes(vector<vector<int>>& v) {
        int n = v.size() , m = v[0].size();
        for( int i = 0 ; i < n ; i++ )
            if(v[i][0])
                for( int j = 0 ; j < m ; j++ )
                    v[i][j] = !v[i][j];
        for( int j = 0 ; j < m ; j++ )
            for( int i = 0 ; i < n ; i++ )
                if(v[0][j] != v[i][j])
                    return false;
        return true;
    }
};
