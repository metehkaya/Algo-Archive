class Solution {
public:
    int dir[4] = {0,1,0,-1};
    int minDayskVariants(vector<vector<int>>& points, int k) {
        int n = points.size();
        int dist[n][100][100];
        memset(dist,-1,sizeof(dist));
        queue<vector<int>> q;
        for( int i = 0 ; i < n ; i++ ) {
            auto p = points[i];
            int x = p[0]-1 , y = p[1]-1;
            dist[i][x][y] = 0;
            q.push({i,x,y});
        }
        int cnt[100][100];
        memset(cnt,0,sizeof(cnt));
        int ans = -1;
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            int idx = v[0] , x = v[1] , y = v[2];
            int d = dist[idx][x][y];
            if(++cnt[x][y] >= k) {
                ans = d;
                break;
            }
            for( int i = 0 ; i < 4 ; i++ ) {
                int xx = x+dir[i];
                int yy = y+dir[i^1];
                if(xx < 0 or xx >= 100 or yy < 0 or yy >= 100)
                    continue;
                if(dist[idx][xx][yy] == -1) {
                    q.push({idx,xx,yy});
                    dist[idx][xx][yy] = d+1;
                }
            }
        }
        return ans;
    }
};
