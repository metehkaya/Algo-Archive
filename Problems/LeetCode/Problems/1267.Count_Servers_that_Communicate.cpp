class Solution {
public:
    const int MAXN = 250;
    int countServers(vector<vector<int>>& ar) {
        vector<int> row(MAXN,0);
        vector<int> col(MAXN,0);
        int n = ar.size();
        int m = ar[0].size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( ar[i][j] == 1 )
                    row[i]++ , col[j]++;
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( ar[i][j] )
                    if( max(row[i],col[j]) > 1 )
                    ans++;
        return ans;
    }
};