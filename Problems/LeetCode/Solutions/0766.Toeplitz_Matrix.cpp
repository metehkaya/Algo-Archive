class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& ar) {
        int n = ar.size();
        if(n == 0)
            return true;
        int m = ar[0].size();
        if(m == 0)
            return true;
        vector<int>val(n+m-1,-1);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                int id = i-j+m-1;
                if(val[id] != -1 && ar[i][j] != val[id])
                    return false;
                val[id] = ar[i][j];
            }
        return true;
    }
};