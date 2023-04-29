#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int dir[4] = {0,1,0,-1};
    vector<vector<int>> highestPeak(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size();
        vector< vector<int> > ans(n,vector<int>(m,-1));
        queue<pi> Q;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == 1) {
                    ans[i][j] = 0;
                    Q.push(pi(i,j));
                }
        while(!Q.empty()) {
            pi temp = Q.front();
            Q.pop();
            int r = temp.fi;
            int c = temp.se;
            int d = ans[r][c];
            for( int i = 0 ; i < 4 ; i++ ) {
                int r2 = r+dir[i];
                int c2 = c+dir[i^1];
                if(r2 >= 0 && r2 < n && c2 >= 0 && c2 < m && ans[r2][c2] == -1) {
                    Q.push(pi(r2,c2));
                    ans[r2][c2] = d+1;
                }
            }
        }
        return ans;
    }
};