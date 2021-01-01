class Solution {
public:
    const int DIR[4][2] = {{0,-1},{0,+1},{-1,0},{+1,0}};
    void dfs(vector<vector<int>>& ar , int r , int c , int& minr , int& maxr , int& minc , int& maxc) {
        ar[r][c] = 1;
        minr = min(minr,r);
        minc = min(minc,c);
        maxr = max(maxr,r);
        maxc = max(maxc,c);
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + DIR[i][0];
            int y = c + DIR[i][1];
            if(x < 0 || x >= ar.size() || y < 0 || y >= ar[0].size())
                continue;
            if(ar[x][y] == 1)
                continue;
            dfs(ar,x,y,minr,maxr,minc,maxc);
        }
    }
    int closedIsland(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( ar[i][j] == 0 ) {
                    int minr = i , maxr = i;
                    int minc = j , maxc = j;
                    dfs(ar,i,j,minr,maxr,minc,maxc);
                    if(minr == 0 || maxr == n-1 || minc == 0 || maxc == m-1)
                        continue;
                    ans++;
                }
        return ans;
    }
};