class Solution {
public:
    const int maxv = (int) 1e6;
    static const int maxn = 100;
    int n,m;
    bool mark[maxn][maxn];
    vector<vector<int>> ar;
    int dir[4] = {0,1,0,-1};
    void dfs(int r , int c , int diff) {
        mark[r][c] = true;
        for( int i = 0 ; i < 4 ; i++ ) {
            int r2 = r+dir[i];
            int c2 = c+dir[i^1];
            if(r2 >= 0 && r2 < n && c2 >= 0 && c2 < m)
                if(!mark[r2][c2] && abs(ar[r][c]-ar[r2][c2]) <= diff)
                    dfs(r2,c2,diff);
        }
    }
    int minimumEffortPath(vector<vector<int>>& ar) {
        this->ar = ar;
        n = ar.size() , m = ar[0].size();
        int l = 0 , r = maxv , ans = -1;
        while(l <= r) {
            int mid = (l+r)>>1;
            memset(mark,false,sizeof(mark));
            dfs(0,0,mid);
            if(mark[n-1][m-1])
                ans = mid , r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
};