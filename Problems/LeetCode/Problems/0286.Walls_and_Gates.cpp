#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    void wallsAndGates(vector<vector<int>>& ar) {
        int n = ar.size();
        if(n == 0)
            return;
        int m = ar[0].size();
        if(m == 0)
            return;
        queue<pi> Q;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == 0)
                    Q.push(pi(i,j));
        while(!Q.empty()) {
            pi temp = Q.front();
            Q.pop();
            int r = temp.fi;
            int c = temp.se;
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r+dx[i];
                int y = c+dy[i];
                if(x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if(ar[x][y] != INT_MAX)
                    continue;
                Q.push(pi(x,y));
                ar[x][y] = ar[r][c]+1;
            }
        }
    }
};