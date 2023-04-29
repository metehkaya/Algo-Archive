class TicTacToe {
public:
    int n;
    vector<vector<int>>ar;
    TicTacToe(int n) {
        this->n = n;
        ar.resize(n,vector<int>(n,0));
    }
    bool checkCol(int col, int player) {
        for( int i = 0 ; i < n ; i++ )
            if( ar[i][col] != player )
                return false;
        return true;
    }
    bool checkRow(int row, int player) {
        for( int i = 0 ; i < n ; i++ )
            if( ar[row][i] != player )
                return false;
        return true;
    }
    bool checkDia1(int player) {
        for( int i = 0 ; i < n ; i++ )
            if( ar[i][i] != player )
                return false;
        return true;
    }
    bool checkDia2(int player) {
        for( int i = 0 ; i < n ; i++ )
            if( ar[i][n-1-i] != player )
                return false;
        return true;
    }
    int move(int row, int col, int player) {
        ar[row][col] = player;
        if(checkRow(row,player))
            return player;
        if(checkCol(col,player))
            return player;
        if(row-col == 0 && checkDia1(player))
            return player;
        if(row+col == n-1 && checkDia2(player))
            return player;
        return 0;
    }
};