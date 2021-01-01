class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& ar) {
        vector<int> row(n,0);
        vector<int> col(m,0);
        for( int i = 0 ; i < ar.size() ; i++ )
            row[ar[i][0]]++ , col[ar[i][1]]++;
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( (row[i] + col[j]) % 2 )
                    ans++;
        return ans;
    }
};