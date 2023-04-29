class Solution {
public:
    bool validTicTacToe(vector<string>& s) {
        int cntX = 0 , cntO = 0;
        for( int i = 0 ; i < 3 ; i++ )
            for( int j = 0 ; j < 3 ; j++ )
                if(s[i][j] == 'X')
                    cntX++;
                else if(s[i][j] == 'O')
                    cntO++;
        if(cntX-cntO != 0 and cntX-cntO != 1)
            return false;
        int cntComboX = 0 , cntComboO = 0;
        for( int r = 0 ; r < 3 ; r++ )
            if(s[r][0] == s[r][1] and s[r][1] == s[r][2]) {
                if(s[r][0] == 'X')
                    cntComboX++;
                else if(s[r][0] == 'O')
                    cntComboO++;
            }
        for( int c = 0 ; c < 3 ; c++ )
            if(s[0][c] == s[1][c] and s[1][c] == s[2][c]) {
                if(s[0][c] == 'X')
                    cntComboX++;
                else if(s[0][c] == 'O')
                    cntComboO++;
            }
        if(s[0][0] == s[1][1] and s[1][1] == s[2][2]) {
            if(s[0][0] == 'X')
                cntComboX++;
            else if(s[0][0] == 'O')
                cntComboO++;
        }
        if(s[0][2] == s[1][1] and s[1][1] == s[2][0]) {
            if(s[0][2] == 'X')
                cntComboX++;
            else if(s[0][2] == 'O')
                cntComboO++;
        }
        if(cntComboX and cntComboO)
            return false;
        if(cntComboX and cntX==cntO)
            return false;
        if(cntComboO and cntX==cntO+1)
            return false;
        return true;
    }
};
