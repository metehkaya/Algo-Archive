class Solution {
public:
    int dir[4] = {0,1,0,-1};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<vector<int>> q;
        vector<vector<int>> dist(n,vector<int>(n,-1));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                if(grid[i][j]) {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            int r = v[0] , c = v[1];
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r+dir[i] , y = c+dir[i^1];
                if(x < 0 or x >= n or y < 0 or y >= n or dist[x][y] != -1)
                    continue;
                q.push({x,y});
                dist[x][y] = dist[r][c] + 1;
            }
        }
        vector<vector<int>> ans(n,vector<int>(n,-1));
        ans[0][0] = dist[0][0];
        priority_queue<vector<int>> heap;
        heap.push({dist[0][0],0,0});
        while(!heap.empty()) {
            auto v = heap.top();
            heap.pop();
            int r = v[1] , c = v[2] , d = v[0];
            if(r == n-1 and c == n-1)
                return d;
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r+dir[i] , y = c+dir[i^1];
                if(x < 0 or x >= n or y < 0 or y >= n)
                    continue;
                int d_new = min(d,dist[x][y]);
                if(d_new > ans[x][y]) {
                    ans[x][y] = d_new;
                    heap.push({d_new,x,y});
                }
            }
        }
        return -1;
    }
};
