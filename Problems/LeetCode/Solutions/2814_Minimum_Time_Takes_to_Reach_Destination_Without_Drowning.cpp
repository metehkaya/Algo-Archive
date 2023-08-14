class Solution {
public:
    int dir[4] = {0,1,0,-1};
    int minimumSeconds(vector<vector<string>>& s) {
        int n = s.size() , m = s[0].size() , src_r , src_c;
        queue<vector<int>> q;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        vector<vector<int>> dist_src(n,vector<int>(m,INT_MAX));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(s[i][j] == "*") {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
                else if(s[i][j] == "S") {
                    src_r = i;
                    src_c = j;
                    dist_src[i][j] = 0;
                }
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            int r = v[0] , c = v[1];
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r+dir[i] , y = c+dir[i^1];
                if(x < 0 or x >= n or y < 0 or y >= m or dist[x][y] != INT_MAX or s[x][y] == "D" or s[x][y] == "X")
                    continue;
                q.push({x,y});
                dist[x][y] = dist[r][c]+1;
            }
        }
        q.push({src_r,src_c});
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            int r = v[0] , c = v[1];
            if(s[r][c] == "D")
                return dist_src[r][c];
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r+dir[i] , y = c+dir[i^1];
                if(x < 0 or x >= n or y < 0 or y >= m or dist_src[x][y] != INT_MAX or s[x][y] == "X" or (dist[x][y] != INT_MAX and dist[x][y] <= dist_src[r][c]+1))
                    continue;
                q.push({x,y});
                dist_src[x][y] = dist_src[r][c]+1;
            }
        }
        return -1;
    }
};
