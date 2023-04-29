#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int dir[4] = {0,1,0,-1};
    int nearestExit(vector<vector<char>>& ar, vector<int>& start) {
        int n = ar.size();
        int m = ar[0].size();
        int R = start[0] , C = start[1];
        int dist[n][m];
        memset(dist,-1,sizeof(dist));
        queue<pi> Q;
        Q.push(pi(R,C));
        dist[R][C] = 0;
        while(!Q.empty()) {
            pi temp = Q.front();
            Q.pop();
            int r = temp.fi;
            int c = temp.se;
            if(r == 0 || r == n-1 || c == 0 || c == m-1)
                if(r != R || c != C)
                    return dist[r][c];
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r + dir[i];
                int y = c + dir[i^1];
                if(x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if(dist[x][y] != -1 || ar[x][y] == '+')
                    continue;
                Q.push(pi(x,y));
                dist[x][y] = dist[r][c]+1;
            }
        }
        return -1;
    }
};