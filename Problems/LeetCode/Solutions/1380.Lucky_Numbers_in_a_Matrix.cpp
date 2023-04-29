class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<int> minRow(n,INT_MAX);
        vector<int> maxCol(m,INT_MIN);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                minRow[i] = min( minRow[i] , ar[i][j] );
                maxCol[j] = max( maxCol[j] , ar[i][j] );
            }
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( ar[i][j] == minRow[i] && ar[i][j] == maxCol[j] )
                    ans.push_back(ar[i][j]);
        return ans;
    }
};