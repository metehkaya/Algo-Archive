#define fi first
#define se second
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

class Solution {
public:
    const int DIR[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int shortestPath(vector<vector<int>>& ar, int k) {
        int n = ar.size();
        int m = ar[0].size();
        queue<pii> Q;
        int dist[n][m][k+1];
        memset(dist,-1,sizeof(dist));
        dist[0][0][0] = 0;
        Q.push(pii(pi(0,0),0));
        while(!Q.empty()) {
            pii temp = Q.front();
            Q.pop();
            int r = temp.fi.fi;
            int c = temp.fi.se;
            int a = temp.se;
            if(r == n-1 && c == m-1)
                return dist[r][c][a];
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r + DIR[i][0];
                int y = c + DIR[i][1];
                if(x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                int b = a + ar[x][y];
                if(b > k)
                    continue;
                if(dist[x][y][b] != -1)
                    continue;
                Q.push(pii(pi(x,y),b));
                dist[x][y][b] = dist[r][c][a] + 1;
            }
        }
        return -1;
    }
};