class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& v) {
        int n = v.size() , m = v[0].size();
        vector<vector<bool>> mark_1(n,vector<bool>(m,false));
        vector<vector<bool>> mark_2(n,vector<bool>(m,false));
        mark_1[0][0] = true;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(v[i][j]) {
                    if(i)
                        mark_1[i][j] = mark_1[i][j] || mark_1[i-1][j];
                    if(j)
                        mark_1[i][j] = mark_1[i][j] || mark_1[i][j-1];
                }
        mark_2[n-1][m-1] = true;
        for( int i = n-1 ; i >= 0 ; i-- )
            for( int j = m-1 ; j >= 0 ; j-- )
                if(v[i][j]) {
                    if(i+1 < n)
                        mark_2[i][j] = mark_2[i][j] || mark_2[i+1][j];
                    if(j+1 < m)
                        mark_2[i][j] = mark_2[i][j] || mark_2[i][j+1];
                }
        vector<int> cnt(n+m-1,0);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(mark_1[i][j] and mark_2[i][j])
                    cnt[i+j]++;
        for( int i = 1 ; i < n+m-2 ; i++ )
            if(cnt[i] <= 1)
                return true;
        return false;
    }
};
