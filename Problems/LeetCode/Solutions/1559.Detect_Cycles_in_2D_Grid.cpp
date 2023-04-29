typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    bool ans = false;
    int dir[4] = {0,1,0,-1};
    void dfs(int r , int c , int r2 , int c2 , vector<vector<char>>& ar , vii& mark) {
        mark[r][c] = true;
        int n = ar.size() , m = ar[0].size();
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r+dir[i];
            int y = c+dir[i^1];
            if(x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if(ar[r][c] != ar[x][y])
                continue;
            if(x == r2 && y == c2)
                continue;
            if(mark[x][y])
                ans = true;
            else
                dfs(x,y,r,c,ar,mark);
        }
    }
    bool containsCycle(vector<vector<char>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vii mark(n,vi(m,0));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(!mark[i][j])
                    dfs(i,j,-1,-1,ar,mark);
        return ans;
    }
};