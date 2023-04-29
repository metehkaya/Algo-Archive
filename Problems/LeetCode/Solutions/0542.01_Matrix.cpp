#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int dir[4] = {0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pi> Q;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == 0) {
                    ans[i][j] = 0;
                    Q.push(pi(i,j));
                }
        while(!Q.empty()) {
            pi temp = Q.front();
            Q.pop();
            int r = temp.fi;
            int c = temp.se;
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r + dir[i];
                int y = c + dir[i^1];
                if(x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if(ans[x][y] != -1)
                    continue;
                Q.push(pi(x,y));
                ans[x][y] = ans[r][c] + 1;
            }
        }
        return ans;
    }
};