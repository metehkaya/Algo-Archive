class Solution {
public:
    bool checkValid(vector<vector<int>>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            vector<bool> mark(n+1,false);
            for( int j = 0 ; j < n ; j++ )
                if(mark[ar[i][j]])
                    return false;
                else
                    mark[ar[i][j]] = true;
        }
        for( int j = 0 ; j < n ; j++ ) {
            vector<bool> mark(n+1,false);
            for( int i = 0 ; i < n ; i++ )
                if(mark[ar[i][j]])
                    return false;
                else
                    mark[ar[i][j]] = true;
        }
        return true;
    }
};
