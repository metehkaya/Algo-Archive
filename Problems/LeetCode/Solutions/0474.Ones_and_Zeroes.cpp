class Solution {
public:
    int dp[101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {
        for( int k = 0 ; k < strs.size() ; k++ ) {
            string s = strs[k];
            int len = s.length();
            int x = 0 , y = 0;
            for( int i = 0 ; i < len ; i++ )
                if(strs[k][i] == '0')
                    x++;
                else
                    y++;
            for( int i = m-x ; i >= 0 ; i-- )
                for( int j = n-y ; j >= 0 ; j-- )
                    dp[i+x][j+y] = max(dp[i+x][j+y],dp[i][j]+1);
        }
        return dp[m][n];
    }
};