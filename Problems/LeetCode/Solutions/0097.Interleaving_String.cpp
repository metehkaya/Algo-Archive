class Solution {
public:
    int len[3];
    string str[3];
    int dp[101][101][2];
    int f(int i , int j , int k) {
        if(i == len[0] && j == len[1])
            return dp[i][j][k] = 1;
        if(i == len[0] && k == 0)
            return dp[i][j][k] = 0;
        if(j == len[1] && k == 1)
            return dp[i][j][k] = 0;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        dp[i][j][k] = 0;
        if(k == 0 && str[0][i] == str[2][i+j])
            dp[i][j][k] = ( f(i+1,j,0) > 0 ) || ( f(i+1,j,1) > 0 );
        if(k == 1 && str[1][j] == str[2][i+j])
            dp[i][j][k] = ( f(i,j+1,0) > 0 ) || ( f(i,j+1,1) > 0 );
        return dp[i][j][k];
    }
    bool isInterleave(string s1, string s2, string s3) {
        str[0] = s1;
        str[1] = s2;
        str[2] = s3;
        for( int i = 0 ; i < 3 ; i++ )
            len[i] = str[i].length();
        if(len[2] != len[0] + len[1])
            return false;
        memset(dp,-1,sizeof(dp));
        return (f(0,0,0) > 0) || (f(0,0,1));
    }
};