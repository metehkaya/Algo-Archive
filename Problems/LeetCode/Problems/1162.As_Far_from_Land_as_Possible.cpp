typedef pair<int,int> pi;

class Solution {
public:
    const int DIR[4][2] = {{0,-1},{0,+1},{-1,0},{+1,0}};
    int maxDistance(vector<vector<int>>& ar) {
        vector<pi> locs[2];
        int n = ar.size();
        int m = ar[0].size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                locs[ar[i][j]].push_back(pi(i,j));
        if(locs[0].empty() or locs[1].empty())
            return -1;
        int cnt0 = locs[0].size();
        int cnt1 = locs[1].size();
        queue<pi> Q;
        vector<vector<int>> dist(n,vector<int>(m,-1));
        for( int i = 0 ; i < cnt1 ; i++ ) {
            pi p = locs[1][i];
            int r = p.first;
            int c = p.second;
            Q.push(p);
            dist[r][c] = 0;
        }
        int ans = 0;
        while(!Q.empty()) {
            pi p = Q.front();
            Q.pop();
            int r = p.first;
            int c = p.second;
            ans = dist[r][c];
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r + DIR[i][0];
                int y = c + DIR[i][1];
                if(x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if(dist[x][y] != -1)
                    continue;
                Q.push(pi(x,y));
                dist[x][y] = dist[r][c] + 1;
            }
        }
        return ans;
    }
};