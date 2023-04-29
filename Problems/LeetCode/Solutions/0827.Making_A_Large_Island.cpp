class Solution {
public:
    int n,m,g,ans;
    int id[500][500];
    int cnt[500*500+1];
    int dir[4] = {0,1,0,-1};
    vector<vector<int>> ar;
    void dfs(int r , int c) {
        cnt[g]++;
        id[r][c] = g;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + dir[i];
            int y = c + dir[i^1];
            if(x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if(id[x][y] || !ar[x][y])
                continue;
            dfs(x,y);
        }
    }
    int largestIsland(vector<vector<int>>& ar) {
        this->ar = ar;
        n = ar.size();
        m = ar[0].size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] && !id[i][j]) {
                    g++;
                    dfs(i,j);
                    ans = max(ans,cnt[g]);
                }
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(!ar[i][j]) {
                    set<int> s;
                    for( int k = 0 ; k < 4 ; k++ ) {
                        int x = i + dir[k];
                        int y = j + dir[k^1];
                        if(x < 0 || x >= n || y < 0 || y >= m)
                            continue;
                        if(id[x][y])
                            s.insert(id[x][y]);
                    }
                    int res = 1;
                    set<int>::iterator it = s.begin();
                    while(it != s.end()) {
                        res += cnt[(*it)];
                        it++;
                    }
                    ans = max(ans,res);
                }
        return ans;
    }
};