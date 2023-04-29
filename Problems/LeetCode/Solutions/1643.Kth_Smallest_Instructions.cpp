class Solution {
public:
    string kthSmallestPath(vector<int>& dest, int k) {
        int n = dest[0] , m = dest[1];
        int N = n+m;
        int dp[N+1][N+1];
        memset(dp,0,sizeof(dp));
        for( int i = 0 ; i <= N ; i++ )
            dp[i][0] = 1;
        for( int i = 1 ; i <= N ; i++ )
            for( int j = 1 ; j <= i ; j++ )
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        string ans = "";
        for( int i = 0 , r = 0 , c = 0 ; i < N ; i++ ) {
            if(c == m) {
                while(r < n) {
                    r++;
                    ans.push_back('V');
                }
                break;
            }
            else {
                int x = n-r;
                int y = m-(c+1);
                int rem = dp[x+y][y];
                if(k <= rem) {
                    c++;
                    ans.push_back('H');
                }
                else {
                    r++;
                    k -= rem;
                    ans.push_back('V');
                }
            }
        }
        return ans;
    }
};