typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;
typedef vector<vb> vbb;

class Solution {
public:
    const int DIR[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int r , int c , int g , int& ans , int n , int m , vii& ar , vbb& mark) {
        g += ar[r][c];
        ans = max(ans , g);
        mark[r][c] = true;
        for( int i = 0 ; i < 4 ; i++ ) {
            int r2 = r + DIR[i][0];
            int c2 = c + DIR[i][1];
            if(r2 < 0 || r2 >= n || c2 < 0 || c2 >= m)
                continue;
            if(!ar[r2][c2] || mark[r2][c2])
                continue;
            dfs(r2,c2,g,ans,n,m,ar,mark);
        }
        mark[r][c] = false;
    }
    int getMaximumGold(vii& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int ans = 0;
        vbb mark(n,vb(m,false));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j])
                    dfs(i,j,0,ans,n,m,ar,mark);
        return ans;
    }
};