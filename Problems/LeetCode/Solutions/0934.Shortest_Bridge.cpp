typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;

class Solution {
public:
    const int DIR[4] = {0,1,0,-1};
    void dfs( int r , int c , int n , int m , vii& ar , vii& dist , queue<pi>& Q ) {
        ar[r][c] = 0;
        dist[r][c] = 0;
        Q.push(pi(r,c));
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + DIR[i];
            int y = c + DIR[i^1];
            if(x == -1 or x == n or y == -1 or y == m or !ar[x][y])
                continue;
            dfs(x,y,n,m,ar,dist,Q);
        }
    }
    int shortestBridge(vii& ar) {
        int n = ar.size() , m = ar[0].size();
        queue<pi> Q;
        vii dist(n,vi(m,-1));
        bool found = false;
        for( int i = 0 ; i < n && !found ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j]) {
                    found = true;
                    dfs(i,j,n,m,ar,dist,Q);
                    break;
                }
        while(!Q.empty()) {
            pi temp = Q.front();
            Q.pop();
            int r = temp.first;
            int c = temp.second;
            if(ar[r][c])
                return dist[r][c] - 1;
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r + DIR[i];
                int y = c + DIR[i^1];
                if(x == -1 or x == n or y == -1 or y == m or dist[x][y] != -1)
                    continue;
                Q.push(pi(x,y));
                dist[x][y] = dist[r][c] + 1;
            }
        }
        return -1;
    }
};