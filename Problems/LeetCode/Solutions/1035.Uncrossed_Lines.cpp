class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<vector<int>> dp( n+1 , vector<int>(m+1,0) );
        for( int i = n-1 ; i >= 0 ; i-- )
            for( int j = m-1 ; j >= 0 ; j-- ) {
                dp[i][j] = max( dp[i][j+1] , dp[i+1][j] );
                if(A[i] == B[j])
                    dp[i][j] = max( dp[i][j] , dp[i+1][j+1] + 1 );
            }
        return dp[0][0];
    }
};