class Solution {
public:
    int countBattleships(vector<vector<char>>& s) {
        int ans = 0;
        int n = s.size();
        int m = s[0].size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( s[i][j] == 'X' )
                    if( ( i == 0 || s[i-1][j] != 'X' ) && ( j == 0 || s[i][j-1] != 'X' ) )
                        ans++;
        return ans;
    }
};