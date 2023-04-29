#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int n,m;
    vector<pi> v;
    bool mark[500][500];
    int dir[4] = {0,1,0,-1};
    void dfs(int r , int c , vector<vector<int>>& ar) {
        v.pb(pi(r,c));
        mark[r][c] = true;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r+dir[i];
            int y = c+dir[i^1];
            if(x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if(mark[x][y] || ar[x][y] == 0)
                continue;
            dfs(x,y,ar);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        n = grid1.size();
        m = grid1[0].size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(grid2[i][j] == 1 && !mark[i][j]) {
                    v.clear();
                    dfs(i,j,grid2);
                    bool ok = true;
                    for( int k = 0 ; k < v.size() ; k++ ) {
                        int r = v[k].fi;
                        int c = v[k].se;
                        if(grid1[r][c] == 0)
                            ok = false;
                    }
                    ans += ok;
                }
        return ans;
    }
};