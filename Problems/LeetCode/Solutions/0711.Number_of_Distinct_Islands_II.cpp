class Solution {
public:
    int n,m;
    int dir[4] = {0,1,0,-1};
    void dfs(int r , int c , vector<vector<int>>& grid , vector<pair<int,int>>& v) {
        grid[r][c] = 0;
        v.push_back({r,c});
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r+dir[i] , y = c+dir[i^1];
            if(x < 0 or x >= n or y < 0 or y >= m or grid[x][y] == 0)
                continue;
            dfs(x,y,grid,v);
        }
    }
    bool add(set<vector<pair<int,int>>>& s , vector<pair<int,int>>& vec) {
        vector<vector<pair<int,int>>> v_all(8);
        for(auto e : vec) {
            v_all[0].push_back({e.first,e.second});
            v_all[1].push_back({e.first,-e.second});
            v_all[2].push_back({-e.first,e.second});
            v_all[3].push_back({-e.first,-e.second});
            v_all[4].push_back({e.second,e.first});
            v_all[5].push_back({e.second,-e.first});
            v_all[6].push_back({-e.second,e.first});
            v_all[7].push_back({-e.second,-e.first});
        }
        for(auto &v : v_all) {
            sort(v.begin() , v.end());
            auto pivot = v[0];
            for(auto& e : v)
                e = {e.first - pivot.first , e.second - pivot.second};
        }
        if(s.find(v_all[0]) == s.end()) {
            for(auto &v : v_all)
                s.insert(v);
            return true;
        }
        return false;
    }
    int numDistinctIslands2(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();
        int ans = 0;
        set<vector<pair<int,int>>> s;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(grid[i][j]) {
                    vector<pair<int,int>> v;
                    dfs(i,j,grid,v);
                    ans += add(s,v);
                }
        return ans;
    }
};
