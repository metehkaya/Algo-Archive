class Solution {
public:
    int dir[4][2] = {{0,-1},{0,+1},{-1,0},{+1,0}};
    bool dfs(int r, int c, int ind, int n, int m, int k, vector<vector<char>>& board, string& word, vector<vector<bool>>& mark) {
        if(ind == k)
            return true;
        mark[r][c] = true;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r+dir[i][0];
            int y = c+dir[i][1];
            if(x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if(mark[x][y])
                continue;
            if(board[x][y] != word[ind])
                continue;
            mark[x][y] = true;
            if( dfs(x,y,ind+1,n,m,k,board,word,mark) )
                return true;
        }
        mark[r][c] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int k = word.length();
        if(!k)
            return true;
        int n = (int) board.size();
        if(!n)
            return false;
        int m = (int) board[0].size();
        if(!m)
            return false;
        vector<vector<bool>> mark(n,vector<bool>(m,false));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( board[i][j] == word[0] )
                    if( dfs(i,j,1,n,m,k,board,word,mark) )
                        return true;
        return false;
    }
};