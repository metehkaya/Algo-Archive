class Solution {
public:
    int n,m;
    int minr,maxr;
    int minc,maxc;
    bool mark[300][300];
    vector<vector<int>> ar;
    int dir[4] = {0,1,0,-1};
    void dfs(int r , int c) {
        mark[r][c] = true;
        minr = min(minr,r);
        maxr = max(maxr,r);
        minc = min(minc,c);
        maxc = max(maxc,c);
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r+dir[i];
            int y = c+dir[i^1];
            if(x >= n || x < 0 || y >= m || y < 0)
                continue;
            if(mark[x][y] || !ar[x][y])
                continue;
            dfs(x,y);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& ar) {
        this->ar = ar;
        n = ar.size();
        m = ar[0].size();
        vector<vector<int>> ans;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] && !mark[i][j]) {
                    minr = INT_MAX , maxr = INT_MIN;
                    minc = INT_MAX , maxc = INT_MIN;
                    dfs(i,j);
                    ans.push_back({minr,minc,maxr,maxc});
                }
        return ans;
    }
};