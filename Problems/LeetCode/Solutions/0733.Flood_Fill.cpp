class Solution {
public:
    const int DIR[4][2] = { {0,-1} , {0,+1} , {-1,0} , {+1,0} };
    void dfs(vector<vector<int>>& ar, int r, int c, int val, int upd) {
        ar[r][c] = upd;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + DIR[i][0];
            int y = c + DIR[i][1];
            if(x >= 0 && x < ar.size() && y >= 0 && y < ar[0].size())
                if( ar[x][y] == val )
                    dfs( ar , x , y , val , upd );
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& ar, int sr, int sc, int upd) {
        if( ar[sr][sc] != upd )
            dfs(ar,sr,sc,ar[sr][sc],upd);
        return ar;
    }
};