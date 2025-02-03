class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& s) {
        for( int i = 0 ; i < 2 ; i++ )
            for( int j = 0 ; j < 2 ; j++ ) {
                int w = 0;
                w += (s[i][j] == 'W');
                w += (s[i][j+1] == 'W');
                w += (s[i+1][j] == 'W');
                w += (s[i+1][j+1] == 'W');
                if(w != 2)
                    return true;
            }
        return false;
    }
};