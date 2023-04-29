class Solution {
public:
    int dir[4] = {0,1,0,-1};
    void dfs(int r , int c , int n , int m , vector<vector<int>>& ar , vector<vector<bool>>& mark) {
        mark[r][c] = true;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + dir[i];
            int y = c + dir[i^1];
            if(x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if(!ar[x][y] || mark[x][y])
                continue;
            dfs(x,y,n,m,ar,mark);
        }
    }
    int nComp(vector<vector<int>>& ar) {
        int cnt = 0;
        int n = ar.size();
        int m = ar[0].size();
        vector<vector<bool>> mark(n,vector<bool>(m,false));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] && !mark[i][j]) {
                    cnt++;
                    dfs(i,j,n,m,ar,mark);
                }
        return cnt;
    }
    int minDays(vector<vector<int>>& ar) {
        if(nComp(ar) != 1)
            return 0;
        for( int i = 0 ; i < ar.size() ; i++ )
            for( int j = 0 ; j < ar[0].size() ; j++ )
                if(ar[i][j]) {
                    ar[i][j] = 0;
                    if(nComp(ar) != 1)
                        return 1;
                    ar[i][j] = 1;
                }
        return 2;
    }
};