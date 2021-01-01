typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int minCost(int m, vector<int>& ar) {
        ar.push_back(0);
        ar.push_back(m);
        int n = ar.size();
        sort(ar.begin(),ar.end());
        vii dp(n+1,vi(n+1));
        for( int i = 0 ; i < n-1 ; i++ )
            dp[i][i+1] = 0;
        for( int len = 3 ; len <= n ; len++ )
            for( int i = 0 ; i <= n-len ; i++ ) {
                int j = i+len-1;
                dp[i][j] = INT_MAX;
                for( int k = i+1 ; k < j ; k++ )
                    dp[i][j] = min( dp[i][j] , dp[i][k]+dp[k][j] );
                dp[i][j] += ar[j]-ar[i];
            }
        return dp[0][n-1];
    }
};