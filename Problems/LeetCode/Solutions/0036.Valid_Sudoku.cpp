class Solution {
public:
    vector<vector<char>> ar;
    void check(int& bmask, char c, bool& ok) {
        if(c == '.')
            return;
        int val = c-'1';
        if(bmask & (1<<val))
            ok = false;
        else
            bmask |= (1<<val);
    }
    bool checkSq(int r , int c) {
        bool ok = true;
        int bmask = 0;
        for( int i = 0 ; i < 3 ; i++ )
            for( int j = 0 ; j < 3 ; j++ )
                check(bmask,ar[3*r+i][3*c+j],ok);
        return ok;
    }
    bool checkCol(int j) {
        bool ok = true;
        int bmask = 0;
        for( int i = 0 ; i < 9 ; i++ )
            check(bmask,ar[i][j],ok);
        return ok;
    }
    bool checkRow(int i) {
        bool ok = true;
        int bmask = 0;
        for( int j = 0 ; j < 9 ; j++ )
            check(bmask,ar[i][j],ok);
        return ok;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        ar = board;
        bool ans = true;
        for( int i = 0 ; i < 9 ; i++ )
            if(!checkRow(i))
                ans = false;
        for( int i = 0 ; i < 9 ; i++ )
            if(!checkCol(i))
                ans = false;
        for( int i = 0 ; i < 9 ; i++ )
            if(!checkSq(i/3,i%3))
                ans = false;
        return ans;
    }
};