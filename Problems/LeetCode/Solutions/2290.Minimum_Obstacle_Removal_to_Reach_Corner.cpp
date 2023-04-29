typedef pair<int,int> pi;

class Solution {
public:
    int dir[4] = {0,1,0,-1};
    int minimumObstacles(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size();
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        queue<pi> q, qNext;
        dist[0][0] = 0;
        q.push(pi(0,0));
        bool found = false;
        for( int d = 0 ; !found ; d++ ) {
            while(!q.empty()) {
                pi p = q.front();
                q.pop();
                int r = p.first , c = p.second;
                if(d > dist[r][c])
                    continue;
                if(r == n-1 && c == m-1)
                    return dist[r][c];
                for( int i = 0 ; i < 4 ; i++ ) {
                    int r2 = r + dir[i];
                    int c2 = c + dir[i^1];
                    if(r2 < 0 || r2 >= n || c2 < 0 || c2 >= m)
                        continue;
                    int d2 = d + ar[r2][c2];
                    if(d2 >= dist[r2][c2])
                        continue;
                    dist[r2][c2] = d2;
                    if(ar[r2][c2] == 0)
                        q.push(pi(r2,c2));
                    else
                        qNext.push(pi(r2,c2));
                }
            }
            swap(q,qNext);
        }
        return dist[n-1][m-1];
    }
};
