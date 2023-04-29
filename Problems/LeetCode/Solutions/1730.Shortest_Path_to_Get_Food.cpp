class Solution {
public:
    int dir[4] = {0,1,0,-1};
    int getFood(vector<vector<char>>& s) {
        int n = s.size() , m = s[0].size();
        queue<vector<int>> q;
        vector<vector<int>> dist(n,vector<int>(m,-1));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(s[i][j] == '*') {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
        while(!q.empty()) {
            vector<int> pos = q.front();
            q.pop();
            int r = pos[0] , c = pos[1];
            if(s[r][c] == '#')
                return dist[r][c];
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r+dir[i] , y = c+dir[i^1];
                if(x < 0 or x >= n or y < 0 or y >= m)
                    continue;
                if(s[x][y] == 'X' or dist[x][y] != -1)
                    continue;
                q.push({x,y});
                dist[x][y] = dist[r][c]+1;
            }
        }
        return -1;
    }
};
