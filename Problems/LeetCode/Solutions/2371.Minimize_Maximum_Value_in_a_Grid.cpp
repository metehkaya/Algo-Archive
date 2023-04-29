class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> adj[n][m];
        vector<vector<int>> indeg(n,vector<int>(m,0));
        for( int i = 0 ; i < n ; i++ ) {
            vector<vector<int>> v;
            for( int j = 0 ; j < m ; j++ )
                v.push_back({grid[i][j],j});
            sort(v.begin(),v.end());
            for( int j = 1 ; j < m ; j++ ) {
                int idx1 = v[j-1][1];
                int idx2 = v[j][1];
                adj[i][idx1].push_back({i,idx2});
                indeg[i][idx2]++;
            }
        }
        for( int i = 0 ; i < m ; i++ ) {
            vector<vector<int>> v;
            for( int j = 0 ; j < n ; j++ )
                v.push_back({grid[j][i],j});
            sort(v.begin(),v.end());
            for( int j = 1 ; j < n ; j++ ) {
                int idx1 = v[j-1][1];
                int idx2 = v[j][1];
                adj[idx1][i].push_back({idx2,i});
                indeg[idx2][i]++;
            }
        }
        queue<vector<int>> q;
        vector<vector<int>> ans(n,vector<int>(m,0));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(indeg[i][j] == 0) {
                    q.push({i,j});
                    ans[i][j] = 1;
                }
        while(!q.empty()) {
            auto vec = q.front();
            q.pop();
            int i = vec[0] , j = vec[1];
            for(auto& cell : adj[i][j]) {
                int x = cell[0] , y = cell[1];
                if(--indeg[x][y] == 0) {
                    q.push({x,y});
                    ans[x][y] = ans[i][j]+1;
                }
            }
        }
        return ans;
    }
};
