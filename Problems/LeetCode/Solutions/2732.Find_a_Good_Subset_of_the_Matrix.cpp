class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& v) {
        int n = v.size() , m = v[0].size();
        int M = (1<<m);
        vector<int> idx(M,-1);
        for( int i = 0 ; i < n ; i++ ) {
            int bmask = 0;
            for( int j = 0 ; j < m ; j++ )
                bmask = 2*bmask + v[i][j];
            idx[bmask] = i;
        }
        if(idx[0] != -1)
            return {idx[0]};
        for( int i = 0 ; i < M ; i++ )
            for( int j = i+1 ; j < M ; j++ )
                if((i & j) == 0 and idx[i] != -1 and idx[j] != -1)
                    return {min(idx[i],idx[j]),max(idx[i],idx[j])};
        return {};
    }
};
