#define mod 1000000007
typedef pair<int,int> pi;

class Solution {
public:
    static const int maxv = 100001;
    vector<pi> indices[maxv];
    int dir[4] = {0,1,0,-1};
    int countPaths(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int dp[n][m];
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                indices[ar[i][j]].push_back(pi(i,j));
        int ans = 0;
        for( int v = maxv-1 ; v > 0 ; v-- ) {
            int sz = indices[v].size();
            for( int i = 0 ; i < sz ; i++ ) {
                pi pos = indices[v][i];
                int r = pos.first;
                int c = pos.second;
                dp[r][c] = 1;
                for( int k = 0 ; k < 4 ; k++ ) {
                    int x = r + dir[k];
                    int y = c + dir[k^1];
                    if(x < 0 || x >= n || y < 0 || y >= m)
                        continue;
                    if(ar[x][y] > ar[r][c])
                        dp[r][c] = (dp[r][c] + dp[x][y]) % mod;
                }
                ans = (ans + dp[r][c]) % mod;
            }
        }
        return ans;
    }
};
