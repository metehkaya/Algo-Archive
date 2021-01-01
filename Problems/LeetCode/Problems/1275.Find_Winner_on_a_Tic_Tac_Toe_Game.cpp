class Solution {
public:
    bool check(vector<vector<int>>& mat , int type) {
        for( int i = 0 ; i < 3 ; i++ ) {
            int cnt1 = 0 , cnt2 = 0;
            for( int j = 0 ; j < 3 ; j++ ) {
                cnt1 += mat[i][j] == type;
                cnt2 += mat[j][i] == type;
            }
            if(max(cnt1,cnt2) == 3)
                return true;
        }
        if(mat[0][0] == type && mat[1][1] == type && mat[2][2] == type)
            return true;
        if(mat[0][2] == type && mat[1][1] == type && mat[2][0] == type)
            return true;
        return false;
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> mat(3,vector<int>(3,-1));
        for( int i = 0 ; i < moves.size() ; i += 2 )
            mat[moves[i][0]][moves[i][1]] = 1;
        for( int i = 1 ; i < moves.size() ; i += 2 )
            mat[moves[i][0]][moves[i][1]] = 0;
        if(check(mat,1))
            return "A";
        if(check(mat,0))
            return "B";
        return (moves.size() == 9) ? "Draw" : "Pending";
    }
};