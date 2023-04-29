class Solution {
public:
    static const int maxn = 300;
    int n,m,ans;
    vector<vector<int>> v;
    bool mark[maxn][maxn][4];
    bool visited[maxn][maxn];
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int i , int j , int k) {
        ans += !visited[i][j];
        visited[i][j] = true;
        if(mark[i][j][k])
            return;
        mark[i][j][k] = true;
        int r = i+dir[k][0];
        int c = j+dir[k][1];
        if(r < 0 or r >= n or c < 0 or c >= m or v[r][c] == 1)
            dfs(i,j,(k+1)%4);
        else
            dfs(r,c,k);
    }
    int numberOfCleanRooms(vector<vector<int>>& v) {
        ans = 0;
        this->v = v;
        n = v.size();
        m = v[0].size();
        memset(mark,false,sizeof(mark));
        memset(visited,false,sizeof(visited));
        dfs(0,0,0);
        return ans;
    }
};
