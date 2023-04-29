class Solution {
public:
    int dir[4] = {0,1,0,-1};
    void dfs(int r , int c , int same , vector<vector<int>>& ar , vector<vector<int>>& ch , vector<vector<bool>>& mark) {
        mark[r][c] = true;
        vector<int> v(2);
        v[0] = r , v[1] = c;
        int n = ar.size() , m = ar[0].size();
        bool ok = false;
        if(r == 0 || r == n-1 || c == 0 || c == m-1)
        ok = true;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r+dir[i];
            int y = c+dir[i^1];
            if(x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if(ar[x][y] != same)
                ok = true;
            else if(!mark[x][y])
                dfs(x,y,same,ar,ch,mark);
        }
        if(ok)
            ch.push_back(v);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& ar, int r, int c, int col) {
        int n = ar.size();
        int m = ar[0].size();
        if(ar[r][c] == col)
            return ar;
        vector<vector<int>> ch;
        vector<vector<bool>> mark(n,vector<bool>(m,false));
        dfs(r,c,ar[r][c],ar,ch,mark);
        for( int i = 0 ; i < ch.size() ; i++ )
            ar[ch[i][0]][ch[i][1]] = col;
        return ar;
    }
};